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

/*
\U0001f9e0 INTUITION:
-----------------------------------
In a Binary Search Tree (BST), the inorder traversal (Left → Root → Right)
always gives the nodes in **sorted order**.

So, if we perform an inorder traversal and store the elements in an array,
the k-th smallest element in that array will be the k-th smallest element in the BST.

For example:
If the BST gives inorder = [1, 2, 3, 4, 5]
→ 1st smallest = 1
→ 3rd smallest = 3
→ 5th smallest = 5

Hence, we can solve this problem by doing a simple inorder traversal.

⚙️ APPROACH:
-----------------------------------
1. Perform an inorder traversal of the BST.
2. Store all node values in a vector (which will be sorted automatically due to inorder property).
3. Return the (k-1)th index value from the vector, as array indices start from 0.

\U0001f9e9 Example:
Input: root = [3,1,4,null,2], k = 1
Inorder Traversal: [1,2,3,4]
Output: 1  (the 1st smallest element)

✅ This is a simple and clear approach that works well for small or medium trees.
*/

class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        vector<int> arr;          // Stores inorder traversal (sorted values)
        inorder(root, arr);
        int result = arr[k - 1];  // k-th smallest is at (k-1) index
        return result;
    }

private:
    // Recursive inorder traversal
    void inorder(TreeNode* node, vector<int>& arr) {
        if (node == nullptr) {
            return;
        }
        inorder(node->left, arr);      // Visit left subtree
        arr.push_back(node->val);      // Visit current node
        inorder(node->right, arr);     // Visit right subtree
    }
};

/*
⏱️ TIME COMPLEXITY:
-----------------------------------
O(N) – We visit each node exactly once during inorder traversal,
where N is the total number of nodes in the BST.

\U0001f4be SPACE COMPLEXITY:
-----------------------------------
O(N) – We store all node values in a vector of size N.

⚡ OPTIMIZATION POSSIBILITY:
-----------------------------------
We can reduce space to O(h) (where h = height of tree) by doing
inorder traversal iteratively and stopping once we find the k-th element
without storing all values.
But this current version is simpler and easier to understand.
*/
