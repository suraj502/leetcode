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
    void path(TreeNode*root,vector<string>&ans,string curr){
        if(root==NULL){
            return;
          }
           curr += to_string(root->val);
        if(root->left==NULL && root->right==NULL){
            ans.push_back(curr);
            
            return;
        }
          curr += "->";
        path(root->left,ans,curr);
        path(root->right,ans,curr);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string>ans;
        string curr="";
        path(root,ans,curr);
        return ans;
    }
};