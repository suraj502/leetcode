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
    vector<int> rightSideView(TreeNode* root) {
     
        vector<int>ans;
           if(root==NULL)return ans;
        map<int,int>mp;
        queue<pair<TreeNode*,int>>q;
        q.push({root,0});
        while(!q.empty()){
            auto p=q.front();
            q.pop();
            TreeNode* value=p.first;
            int row=p.second;
            if(mp.find(row)==mp.end()){
                mp[row]=value->val; }

        
        if(value->right!=NULL){
        q.push({value->right,row+1});
        }
          if(value->left!=NULL){
        q.push({value->left,row+1});
        }
        }
        for(auto it:mp){
            ans.push_back(it.second);
        }
        return ans;
    }
};