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
    int amountOfTime(TreeNode* root, int start) {
        // ---------- Step 1: Build parent mapping and find start node ----------
        map<TreeNode*, TreeNode*> parent;    // stores each node's parent
        TreeNode* startNode = nullptr;

        queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            // Find the node with value == start
            if (node->val == start) {
                startNode = node;
            }

            // Map child -> parent for both left and right
            if (node->left) {
                parent[node->left] = node;
                q.push(node->left);
            }
            if (node->right) {
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // ---------- Step 2: BFS from the start node ----------
        map<TreeNode*, bool> visited;
        queue<TreeNode*> bfs;

        bfs.push(startNode);
        visited[startNode] = true;

        int dist = -1;  // start at -1 because after first level it becomes 0

        while (!bfs.empty()) {
            int size = bfs.size();

            // Process one BFS level (one minute passes)
            for (int i = 0; i < size; i++) {
                TreeNode* curr = bfs.front();
                bfs.pop();

                // Infect left child
                if (curr->left && !visited[curr->left]) {
                    visited[curr->left] = true;
                    bfs.push(curr->left);
                }
                // Infect right child
                if (curr->right && !visited[curr->right]) {
                    visited[curr->right] = true;
                    bfs.push(curr->right);
                }
                // Infect parent
                if (parent.count(curr) && !visited[parent[curr]]) {
                    visited[parent[curr]] = true;
                    bfs.push(parent[curr]);
                }
            }

            dist++; // after finishing one level (one minute)
        }

        // dist is the number of minutes to infect all nodes
        return dist;
    }
};
