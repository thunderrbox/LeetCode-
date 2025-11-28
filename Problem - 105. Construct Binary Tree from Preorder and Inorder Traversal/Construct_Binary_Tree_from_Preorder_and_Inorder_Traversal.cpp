/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 *                                                        right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        /*
            INTUITION:
            ----------
            - Preorder traversal gives nodes in the order: ROOT → LEFT → RIGHT.
            - Inorder traversal gives nodes in the order: LEFT → ROOT → RIGHT.
            - The first element of preorder is always the root of the tree.
            - Using the root's position in the inorder array, we can split the
           tree into left and right subtrees.

            WHY HASHMAP?
            ------------
            - We need to quickly find root's index in inorder[].
            - Searching every time would be O(n), making total O(n^2).
            - A hashmap allows O(1) lookup → total time becomes O(n).

            OVERALL STRATEGY:
            -----------------
            - Take root from preorder.
            - Find root in inorder using hashmap.
            - Determine how many nodes belong to the left subtree.
            - Recursively build:
                * Left subtree
                * Right subtree
        */

        unordered_map<int, int> inMap; // value -> index in inorder
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i; // store index for O(1) lookup
        }

        return build(preorder, 0, preorder.size() - 1, inorder, 0,
                     inorder.size() - 1, inMap);
    }

private:
    /*
        FUNCTION PURPOSE:
        -----------------
        build(preorder, preStart, preEnd, inorder, inStart, inEnd, inMap)
        Recursively constructs the binary tree.

        PARAMETERS:
        - preStart, preEnd → range in preorder for current subtree
        - inStart, inEnd → range in inorder for current subtree
    */

    TreeNode* build(vector<int>& preorder, int preStart, int preEnd,
                    vector<int>& inorder, int inStart, int inEnd,
                    unordered_map<int, int>& inMap) {

        // Base Case: No nodes left to build
        if (preStart > preEnd || inStart > inEnd)
            return nullptr;

        /*
            STEP 1: Identify ROOT
            ----------------------
            Since preorder = [ROOT, left subtree..., right subtree...]
            → preorder[preStart] is always the root of the current subtree
        */
        int rootVal = preorder[preStart];
        TreeNode* root = new TreeNode(rootVal);

        /*
            STEP 2: Find root's position in inorder[]
            ------------------------------------------
            inorder = [LEFT SUBTREE ... ROOT ... RIGHT SUBTREE]
            → So split inorder into two parts around the root index.
        */
        int inRoot = inMap[rootVal];     // index of root in inorder
        int numsLeft = inRoot - inStart; // number of nodes in left subtree

        /*
            STEP 3: Build Left Subtree
            ----------------------------
            preorder range:
                preStart + 1 → preStart + numsLeft
            inorder range:
                inStart → inRoot - 1
        */
        root->left = build(preorder, preStart + 1, preStart + numsLeft, inorder,
                           inStart, inRoot - 1, inMap);

        /*
            STEP 4: Build Right Subtree
            -----------------------------
            preorder range:
                preStart + numsLeft + 1 → preEnd
            inorder range:
                inRoot + 1 → inEnd
        */
        root->right = build(preorder, preStart + numsLeft + 1, preEnd, inorder,
                            inRoot + 1, inEnd, inMap);

        // Return constructed root for this subtree
        return root;
    }
};

/*
    TIME COMPLEXITY:
    ----------------
    - Every node is inserted once → O(n)
    - Hashmap lookup for inorder index → O(1)
    => Total Time: O(n)

    SPACE COMPLEXITY:
    -----------------
    - Hashmap storing inorder indices → O(n)
    - Recursion stack (worst case skewed tree) → O(n)
    => Total Space: O(n)

    INTUITION SUMMARY:
    ------------------
    Preorder gives root sequence.
    Inorder gives subtree boundaries.
    Combine them using recursion + hashmap to rebuild the tree efficiently.
*/
