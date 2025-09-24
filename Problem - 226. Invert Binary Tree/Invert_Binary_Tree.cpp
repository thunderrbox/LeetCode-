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

/**
 * Intuition:
 * The problem is to invert (mirror) a binary tree.
 * This means we need to swap the left and right children of every node in the tree.
 *
 * Approach:
 * 1. Use recursion to traverse the tree.
 * 2. For each node:
 *      - Swap its left and right child.
 *      - Recursively repeat the same process for its left subtree and right subtree.
 * 3. Base case: If the current node is NULL, just return.
 *
 * Understanding:
 * Think of this as flipping the entire tree across its vertical axis.
 * Recursion ensures we reach every node and perform the swap locally,
 * which results in the whole tree being inverted.
 *
 * Time Complexity: O(n)  
 *   - We visit each node exactly once and swap its children → O(1) work per node.  
 *   - Total = O(n), where n = number of nodes in the tree.
 *
 * Space Complexity: O(h)  
 *   - Due to recursion stack, where h = height of tree.  
 *   - In worst case (skewed tree), h = n → O(n).  
 *   - In best/average case (balanced tree), h = log(n).
 */

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
        // Base case: if tree is empty, nothing to invert
        if(root == nullptr){
            return root;
        }

        // Swap left and right children
        TreeNode* node = root->left;
        root->left = root->right;
        root->right = node;

        // Recursively invert the left subtree
        invertTree(root->left);

        // Recursively invert the right subtree
        invertTree(root->right);

        // Return the root after inversion
        return root;
    }
};
