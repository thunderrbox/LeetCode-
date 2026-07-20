/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {

        // Index keeps track of the current element in preorder traversal.
        // It is passed by reference so every recursive call shares the same index.
        int index = 0;

        // Initially there is no upper limit,
        // so we use INT_MAX as the maximum possible value.
        return buildBST(index, preorder, INT_MAX);
    }

private:

    // i      -> Current index in preorder array.
    // pre    -> Preorder traversal.
    // bound  -> Maximum value allowed for the current subtree.
    TreeNode* buildBST(int &i, vector<int> pre, int bound) {

        // Base Case 1:
        // All elements have been processed.
        if (i >= pre.size())
            return nullptr;

        // Base Case 2:
        // Current value does not belong to this subtree
        // because it exceeds the allowed upper bound.
        if (pre[i] >= bound)
            return nullptr;

        // Create the current root node.
        TreeNode* node = new TreeNode(pre[i++]);

        // Build left subtree.
        // Every value in left subtree must be smaller than node->val.
        node->left = buildBST(i, pre, node->val);

        // Build right subtree.
        // Right subtree values must be smaller than parent's bound
        // but greater than node->val automatically.
        node->right = buildBST(i, pre, bound);

        return node;
    }
};