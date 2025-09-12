/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    // Main function that will be called externally
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Call the recursive helper function to find LCA
        TreeNode* node = LCA(root, p, q);
        return node; // Return the result from helper
    }

private:
    // Helper function to recursively find LCA
    TreeNode* LCA(TreeNode* &node, TreeNode* &p, TreeNode* &q) {

        // ✅ Base Case 1:
        // If the current node is NULL, return NULL (no node found here)
        // ✅ Base Case 2:
        // If current node is either p or q, return it
        // (because if we find either target, bubble it up)
        if (node == nullptr || node == p || node == q) {
            return node;
        }

        // \U0001f50d Recur on left subtree to search for p and q
        TreeNode* l = LCA(node->left, p, q);

        // \U0001f50d Recur on right subtree to search for p and q
        TreeNode* r = LCA(node->right, p, q);

        // ✅ Decision Step:
        // If left side returned NULL, it means both p and q are on the right side
        if (l == nullptr) {
            return r;
        }
        // If right side returned NULL, it means both p and q are on the left side
        else if (r == nullptr) {
            return l;
        }
        else {
            // If both sides are non-NULL, it means p is on one side and q is on the other side.
            // So the current node is their Lowest Common Ancestor
            return node;
        }
    }
};
