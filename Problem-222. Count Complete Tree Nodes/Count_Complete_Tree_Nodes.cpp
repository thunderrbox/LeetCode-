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
    int countNodes(TreeNode* root) {
        int count = 0;          // Step 1: Initialize count to 0
                                // This variable will store the total number of nodes
        
        traverse(root, count);  // Step 2: Start recursive traversal from root
                                // We pass count by reference so that each recursive call
                                // updates the same count variable
        
        return count;           // Step 3: After traversal, return the total count
    }

private:
    // Recursive helper function to traverse the tree
    void traverse(TreeNode* node, int &count){
        // Step 1: Base case
        // If current node is nullptr, there is nothing to count
        if(node == nullptr){
            return;
        }

        // Step 2: Count current node
        count++;  

        // Step 3: Recur for left subtree
        traverse(node->left, count);

        // Step 4: Recur for right subtree
        traverse(node->right, count);
    }
};

/*
Intuition and Understanding:

1. A binary tree is made of nodes, each of which can have a left and/or right child.
2. To count all nodes, we need to visit each node at least once.
3. Recursive traversal (DFS) is ideal:
   - Visit current node -> increment count
   - Recur for left child
   - Recur for right child
4. Using a reference variable 'count' allows all recursive calls to update the same counter.
5. Base case ensures recursion stops at leaf nodes (nullptr).
6. This approach guarantees that every node is counted exactly once.

Time Complexity: O(n) - each node is visited once
Space Complexity: O(h) - recursion stack, where h is the height of the tree
*/
