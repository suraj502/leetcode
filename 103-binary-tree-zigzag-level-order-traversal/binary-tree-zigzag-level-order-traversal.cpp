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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        if(root==NULL)return ans;
        queue<TreeNode*>q;
        q.push(root);
        bool flag=true;
        while(!q.empty()){
            int s=q.size(); int index;
            vector<int>level(s);
              for(int i=0;i<s;i++){
                TreeNode*a=q.front();
                q.pop();
                if(flag){
                    index=i;
                    level[index]=a->val;
                }
                else{
                    index=s-i-1;
                    level[index]=a->val;
                }
                if(a->left!=NULL){
                    q.push(a->left);
                }
                 if(a->right!=NULL){
                    q.push(a->right);
                }

              }
              ans.push_back(level);
              flag=!flag;
        }
        return ans;
    }
};