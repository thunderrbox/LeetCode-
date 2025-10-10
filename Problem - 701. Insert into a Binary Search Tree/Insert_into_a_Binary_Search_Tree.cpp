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
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        /*
         \U0001f331 Intuition:
         A Binary Search Tree (BST) maintains the property that:
             - All nodes in the left subtree have values < root->val
             - All nodes in the right subtree have values > root->val
         
         To insert a value into a BST:
             1️⃣ Start from the root.
             2️⃣ Compare the value to insert (`val`) with the current node.
             3️⃣ If val < current->val → move to the left subtree.
             4️⃣ If val > current->val → move to the right subtree.
             5️⃣ When you reach a nullptr position (i.e., no left or right child), 
                 create a new TreeNode there — that’s the insertion point.
         */

        // Base case: if the tree is empty, create and return a new node.
        if (root == nullptr) {
            return new TreeNode(val);
        }

        // Pointer to traverse the tree iteratively.
        TreeNode* current = root;

        // Traverse until we find the correct place to insert the new value.
        while (true) {
            // If val is greater, we should go to the right subtree.
            if (val > current->val) {
                if (current->right != nullptr) {
                    // Keep moving right until an empty spot is found.
                    current = current->right;
                } else {
                    // Found the correct position: attach the new node to the right.
                    current->right = new TreeNode(val);
                    break; // Stop traversal after inserting.
                }
            } 
            // If val is smaller, we should go to the left subtree.
            else {
                if (current->left != nullptr) {
                    // Keep moving left until an empty spot is found.
                    current = current->left;
                } else {
                    // Found the correct position: attach the new node to the left.
                    current->left = new TreeNode(val);
                    break; // Stop traversal after inserting.
                }
            }
        }

        // Return the original root of the tree (since it never changes).
        return root;
    }
};
