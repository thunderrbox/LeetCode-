/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {	
public:	
    TreeNode* searchBST(TreeNode* root, int data) {
        // \U0001f50d Intuition:
        // We are searching for a given value 'data' in a Binary Search Tree (BST).
        // In a BST:
        //  - All values in the left subtree are smaller than the root’s value.
        //  - All values in the right subtree are larger than the root’s value.
        // Hence, we can use this property to skip half the nodes each time,
        // similar to how Binary Search works in arrays.

        // ⚙️ Approach:
        // Use an iterative approach (loop-based) instead of recursion.
        // 1. Start from the root.
        // 2. If current node’s value equals 'data', we found the node → return it.
        // 3. If 'data' is smaller, move to the left subtree.
        // 4. If 'data' is larger, move to the right subtree.
        // 5. Continue until root becomes nullptr (not found).

        while (root != nullptr && root->val != data) {  // continue searching until null or found
            if (root->val < data) {
                root = root->right;   // move right if target is greater
            } else {
                root = root->left;    // move left if target is smaller
            }
        }

        // At the end of loop:
        // - If found, 'root' points to the node containing 'data'.
        // - If not found, 'root' becomes nullptr.
        return root;
    }
};
