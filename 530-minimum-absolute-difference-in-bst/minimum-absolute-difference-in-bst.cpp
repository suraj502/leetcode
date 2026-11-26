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
void dfs(TreeNode* root,vector<int>&curr){
    if(root==NULL)return ;
    dfs(root->left,curr);
    curr.push_back(root->val);
    dfs(root->right,curr);


}
    int getMinimumDifference(TreeNode* root) {
        vector<int>curr;
       dfs(root,curr);
      int mini=INT_MAX;
      for(int i=0; i<curr.size()-1;i++){
       int no=abs(curr[i]-curr[i+1]);
       mini=min(mini,no);
      }
      return mini;
    }
};