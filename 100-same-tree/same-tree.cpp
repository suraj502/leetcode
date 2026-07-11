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
   int dfs(TreeNode*p,TreeNode*q){
    if(p==NULL&&q==NULL){
        return 0;
    }
   if(p==NULL || q==NULL){
    return 1;
   }
 if(p->val!=q->val){
return 1;
 }
   int a =dfs(p->left,q->left);
   if(a==1)return 1;
   int b= dfs(p->right,q->right);
   if (b==1)return 1;
 
 return 0;
   }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        int c=dfs(p,q);
        if(c==0){
            return true;
        }
        else{
            return false;
        }
    }
};