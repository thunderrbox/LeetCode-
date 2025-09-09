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
        map<int, map<int, multiset<int>>> mp;
        queue<pair<TreeNode*, pair<int,int>>> q;
        q.push({root, {0, 0}});
        
        while(!q.empty()){
            auto p = q.front();
            q.pop();
            TreeNode* node = p.first;
            int i = p.second.first;   // vertical
            int j = p.second.second;  // level
            mp[i][j].insert(node->val);
            
            if(node->left){
                q.push({node->left,{i - 1, j + 1}});
            }
            if(node->right){
                q.push({node->right, {i + 1, j + 1}});
            }
        }

        vector<vector<int>> ans;
        for(auto& k : mp){
            vector<int> nums;
            for(auto &l : k.second){
                nums.insert(nums.end(), l.second.begin(), l.second.end());
            }
            ans.push_back(nums);
        }
        return ans;
    }
};
