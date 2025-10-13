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
    bool isValidBST(TreeNode* root) { 
        // Call helper function with initial min and max boundaries
        // LLONG_MIN and LLONG_MAX are used to cover the full range of values
        return isBST(root, LLONG_MIN, LLONG_MAX); 
    }

private:
    bool isBST(TreeNode* node, long long mini, long long maxi) {
        // Base case: An empty subtree is a valid BST
        if(node == nullptr){
            return true;
        }

        // If current node violates the min/max constraints, it's not a BST
        if(node->val <= mini || node->val >= maxi){
            return false;
        }

        // Recursively check the left subtree
        // For left subtree, the current node value becomes the new maximum
        bool left = isBST(node->left, mini, node->val);

        // Recursively check the right subtree
        // For right subtree, the current node value becomes the new minimum
        bool right = isBST(node->right, node->val, maxi);

        // Current subtree is valid only if both left and right subtrees are valid
        return left && right;
    }
};

/*
Intuition:
- In a Binary Search Tree (BST):
    - All nodes in the left subtree of a node must be smaller than the node's value.
    - All nodes in the right subtree of a node must be greater than the node's value.
- We recursively enforce this rule for every node using min and max bounds.
- Each node is checked against a valid range (mini, maxi) that updates as we go deeper in the tree.

Understanding:
- `mini` and `maxi` represent the valid range for the current node's value.
- When moving to the left child, the maximum allowed value becomes the parent node's value.
- When moving to the right child, the minimum allowed value becomes the parent node's value.
- If any node violates its valid range, the tree is not a BST.
- Using long long ensures we handle extreme integer values safely.

Time Complexity: O(n)
- We visit each node exactly once.
- n = number of nodes in the tree.

Space Complexity: O(h)
- Recursive call stack depends on the height of the tree, h.
- Worst case (skewed tree): O(n)
- Best case (balanced tree): O(log n)
*/
