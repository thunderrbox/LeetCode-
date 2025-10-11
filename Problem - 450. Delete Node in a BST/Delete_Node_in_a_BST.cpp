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
    // ===================== INTUITION =====================
    // Deletion in a Binary Search Tree depends on how many children a node has:
    //
    // Case 1 → Node has NO children (Leaf node)
    //           → Simply delete the node.
    //
    // Case 2 → Node has ONE child
    //           → Replace the node with its only child.
    //
    // Case 3 → Node has TWO children
    //           → Replace the node’s value with its in-order successor (smallest in right subtree),
    //             then recursively delete that successor node.
    //
    // This approach maintains the BST property (left < root < right) after deletion.

    TreeNode* deleteNode(TreeNode* root, int key) {
        // Base case: empty tree
        if (root == nullptr) return nullptr;

        // If current node is the one to be deleted
        if (root->val == key) {
            return replace(root); // Handle all deletion cases
        }

        TreeNode* curr = root;

        // Traverse the BST to locate node with the given key
        while (curr != nullptr) {
            if (key < curr->val) {
                // Go to left subtree
                if (curr->left != nullptr && curr->left->val == key) {
                    curr->left = replace(curr->left);
                    break;
                } else {
                    curr = curr->left;
                }
            } else {
                // Go to right subtree
                if (curr->right != nullptr && curr->right->val == key) {
                    curr->right = replace(curr->right);
                    break;
                } else {
                    curr = curr->right;
                }
            }
        }

        return root;
    }

private:
    // ===================== HELPER FUNCTION =====================
    // Handles all deletion cases and returns the new subtree root
    TreeNode* replace(TreeNode* node) {
        // Case 1: No left child
        if (node->left == nullptr) {
            TreeNode* rightChild = node->right;
            delete node;
            return rightChild;
        }

        // Case 2: No right child
        if (node->right == nullptr) {
            TreeNode* leftChild = node->left;
            delete node;
            return leftChild;
        }

        // Case 3: Node has two children
        TreeNode* successor = findMin(node->right);  // find inorder successor
        node->val = successor->val;                   // copy successor value
        node->right = deleteNode(node->right, successor->val); // delete successor
        return node;
    }

    // ===================== FIND MIN FUNCTION =====================
    // Finds the node with minimum value in a BST
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
};

// ===================== UNDERSTANDING =====================
// Example:
// Input BST:          5
//                    / \
//                   3   6
//                  / \   \
//                 2   4   7
//
// Delete key = 3
// Node 3 has two children (2 and 4)
// Inorder successor = 4
// Replace 3 with 4 and delete 4 from right subtree
//
// Result:             5
//                    / \
//                   4   6
//                  /     \
//                 2       7

// ===================== COMPLEXITY ANALYSIS =====================
// Time Complexity: O(h)  → where h = height of the BST
//     - Best/Average (Balanced BST): O(log n)
//     - Worst Case (Skewed Tree): O(n)
//
// Space Complexity: O(h)
//     - Due to recursion stack while deleting inorder successor
//     - O(1) extra space otherwise
