/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */

class Solution {
public:

    /*
    ============================================================
    PROBLEM:
    Construct Binary Tree from Inorder and Postorder Traversal
    ============================================================

    INTUITION:
    ----------
    1) In Postorder traversal:
       LEFT -> RIGHT -> ROOT
       So, the LAST element of postorder is always the ROOT.

    2) In Inorder traversal:
       LEFT -> ROOT -> RIGHT
       If we know the root index in inorder,
       - elements left of root belong to LEFT subtree
       - elements right of root belong to RIGHT subtree

    3) So idea is:
       - Pick root from postorder (last element)
       - Find its index in inorder
       - Recursively build left and right subtree

    4) To find index quickly in O(1),
       we store inorder value -> index in a hashmap.
    */


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {

        /*
        We create a hashmap:
        key   = node value
        value = index in inorder array

        This avoids O(n) search each time.
        */
        unordered_map<int,int> mp;
        for(int i = 0; i < inorder.size(); i++)
            mp[inorder[i]] = i;

        /*
        Call recursive builder function

        Parameters:
        inorder range   -> 0 to n-1
        postorder range -> 0 to n-1
        */
        return buildBT(inorder, 0, inorder.size()-1,
                       postorder, 0, postorder.size()-1, mp);
    }

private:

    /*
    RECURSIVE FUNCTION TO BUILD TREE

    inS, inE  -> start & end of current inorder segment
    pS, pE    -> start & end of current postorder segment

    We shrink these ranges as we move deeper in recursion.
    */

    TreeNode* buildBT(vector<int>& inorder, int inS, int inE,
                      vector<int>& postorder, int pS, int pE,
                      unordered_map<int,int>& mp)
    {
        /*
        BASE CASE:
        If range becomes invalid,
        no nodes exist in this subtree.
        */
        if(inS > inE || pS > pE)
            return NULL;


        /*
        STEP 1:
        Last element of postorder is always the ROOT.
        */
        TreeNode* root = new TreeNode(postorder[pE]);


        /*
        STEP 2:
        Find root index in inorder array
        */
        int inRoot = mp[postorder[pE]];


        /*
        STEP 3:
        Number of nodes in LEFT subtree

        inorder:
        [inS ........ inRoot-1]  root  [inRoot+1 .... inE]

        So,
        left subtree size = inRoot - inS
        */
        int numsLeft = inRoot - inS;


        /*
        STEP 4:
        Build LEFT subtree

        Inorder left part:
        inS -> inRoot-1

        Postorder left part:
        pS -> pS + numsLeft - 1

        Why?
        Because first numsLeft elements in postorder
        belong to left subtree.
        */
        root->left = buildBT(inorder,
                             inS,
                             inRoot - 1,
                             postorder,
                             pS,
                             pS + numsLeft - 1,
                             mp);


        /*
        STEP 5:
        Build RIGHT subtree

        Inorder right part:
        inRoot+1 -> inE

        Postorder right part:
        pS + numsLeft -> pE - 1

        Why pE-1?
        Because pE is root, so exclude it.
        */
        root->right = buildBT(inorder,
                              inRoot + 1,
                              inE,
                              postorder,
                              pS + numsLeft,
                              pE - 1,
                              mp);

        return root;
    }
};


/*
============================================================
FULL APPROACH SUMMARY
============================================================

1) Root is always last element in postorder.
2) Use inorder to split tree into left & right subtree.
3) Recursively repeat same logic for subtrees.
4) Use hashmap to avoid O(n) lookup for index.


============================================================
TIME COMPLEXITY
============================================================

Let n = number of nodes

- Each node is created exactly once -> O(n)
- Hashmap lookup is O(1)
- No repeated scanning of inorder

Total Time Complexity:  O(n)


============================================================
SPACE COMPLEXITY
============================================================

1) Hashmap -> O(n)
2) Recursive stack:
   Worst case (skewed tree) -> O(n)
   Balanced tree -> O(log n)

Total Space Complexity: O(n)


============================================================
WHY THIS IS OPTIMAL?
============================================================

Without hashmap:
Finding root index in inorder takes O(n)
Total complexity becomes O(n^2)

With hashmap:
We reduce it to O(n)

This is the optimal solution.
============================================================
*/
