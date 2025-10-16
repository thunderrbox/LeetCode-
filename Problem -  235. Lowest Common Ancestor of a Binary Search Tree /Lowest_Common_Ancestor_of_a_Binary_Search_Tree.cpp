/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

/**
 * Intuition:
 * ------------
 * In a Binary Search Tree (BST):
 *   - All values in the left subtree are smaller than the current node.
 *   - All values in the right subtree are larger than the current node.
 * 
 * The Lowest Common Ancestor (LCA) of two nodes p and q is the node where
 * the paths to p and q diverge — that is, one node lies in the left subtree,
 * and the other lies in the right subtree.
 * 
 * Approach (Iterative):
 * ----------------------
 * 1. Start from the root.
 * 2. If both p and q are greater than root, move to the right subtree.
 * 3. If both p and q are smaller than root, move to the left subtree.
 * 4. Otherwise, the current root is the split point → return root.
 * 
 * This method avoids recursion, saving stack space.
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base check
        if (root == nullptr) return nullptr;

        // Traverse until LCA is found
        while (root != nullptr) {
            // If both nodes are greater than current node, move right
            if (p->val > root->val && q->val > root->val) {
                root = root->right;
            }
            // If both nodes are smaller than current node, move left
            else if (p->val < root->val && q->val < root->val) {
                root = root->left;
            }
            // Otherwise, we have found the split point (LCA)
            else {
                return root;
            }
        }

        return nullptr; // Should never reach here if p and q exist in BST
    }
};

/**
 * Complexity Analysis:
 * ---------------------
 * Time Complexity:  O(h)
 *    -> where h is the height of the BST.
 *    -> Best Case (Balanced BST): O(log n)
 *    -> Worst Case (Skewed BST):  O(n)
 *
 * Space Complexity: O(1)
 *    -> No recursion or extra stack used (iterative solution).
 */
