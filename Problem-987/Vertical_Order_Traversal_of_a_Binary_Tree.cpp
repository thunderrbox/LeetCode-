/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int data;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : data(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> a;
        map<int,vector<int>> mp;

        if(root ==  NULL) return {};

        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(q.size()){
            int n = q.size();
            map<int,vector<int>>m;
            for(int i = 0 ; i < n ; i++){
                auto it = q.front();
                q.pop();
                m[it.second].push_back(it.first->val);
                if(it.first->left) q.push({it.first->left,it.second-1});
                if(it.first->right) q.push({it.first->right,it.second+1});
            }
            for(auto &x : m){
                sort(begin(x.second),end(x.second));
                for(auto &y : x.second) mp[x.first].push_back(y);
            }
        }

        for(auto &x : mp){
            a.push_back(x.second);
        }

        return a;
    }
};