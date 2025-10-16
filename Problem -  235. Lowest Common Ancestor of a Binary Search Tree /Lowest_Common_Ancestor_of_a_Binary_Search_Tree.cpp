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
 * This problem asks for the Lowest Common Ancestor (LCA) of two nodes in a Binary Search Tree (BST).
 * 
 * In a BST, for every node:
 *      -> All nodes in the left subtree have values smaller than the current node's value.
 *      -> All nodes in the right subtree have values larger than the current node's value.
 * 
 * Using this property, we can efficiently find the LCA without exploring the entire tree.
 * 
 * Logic:
 * -------
 * 1. If the current node (root) is NULL, return NULL (base case).
 * 2. If the current node is equal to either p or q, then it is part of the LCA, so return it.
 * 3. If both p and q have values greater than root->val,
 *        → both are in the right subtree → move to root->right.
 * 4. If both p and q have values smaller than root->val,
 *        → both are in the left subtree → move to root->left.
 * 5. Otherwise, p and q lie in different subtrees,
 *        → the current root is the split point → return root.
 * 
 * This approach uses BST properties to skip irrelevant parts of the tree, making it very efficient.
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base Case: if root is null or matches one of the nodes
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        // If both p and q are greater than root, LCA must be in right subtree
        if (root->val < p->val && root->val < q->val) {
            return lowestCommonAncestor(root->right, p, q);
        }
        // If both p and q are smaller than root, LCA must be in left subtree
        else if (root->val > p->val && root->val > q->val) {
            return lowestCommonAncestor(root->left, p, q);
        }

        // If one lies on the left and the other on the right, current node is LCA
        return root;
    }
};

/**
 * Complexity Analysis:
 * ---------------------
 * Time Complexity:  O(h)
 *    -> where h is the height of the BST.
 *    -> In the best case (balanced tree): O(log n)
 *    -> In the worst case (skewed tree): O(n)
 * 
 * Space Complexity: O(h)
 *    -> due to recursive call stack (height of the tree).
 *    -> In the best case (balanced): O(log n)
 *    -> In the worst case (skewed): O(n)
 */
