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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        // Vector to store (col, row, val)
        vector<tuple<int,int,int>> nodes;

        // BFS queue → (node, col, row)
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});

        while(!q.empty()){
            auto p = q.front(); q.pop();
            TreeNode* node = p.first;
            int col = p.second.first;   // horizontal distance (x-axis)
            int row = p.second.second;  // level (y-axis)

            // Store the node info
            nodes.push_back({col, row, node->val});

            // Left child → col-1, row+1
            if(node->left) 
                q.push({node->left, {col - 1, row + 1}});

            // Right child → col+1, row+1
            if(node->right) 
                q.push({node->right, {col + 1, row + 1}});
        }

        // Sort by col first, then row, then value
        sort(nodes.begin(), nodes.end(), [](auto &a, auto &b){
            if(get<0>(a) != get<0>(b)) return get<0>(a) < get<0>(b); // col
            if(get<1>(a) != get<1>(b)) return get<1>(a) < get<1>(b); // row
            return get<2>(a) < get<2>(b); // value
        });

        // Group values by column
        vector<vector<int>> ans;
        int prevCol = INT_MIN;
        for(auto &t : nodes){
            int col = get<0>(t), val = get<2>(t);

            // Start new column if col changes
            if(col != prevCol){
                ans.push_back({});
                prevCol = col;
            }
            ans.back().push_back(val);
        }

        return ans;
    }
};
