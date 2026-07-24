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
TreeNode* last(TreeNode* curr){
    if(curr->right==NULL){
        return curr;
    }
   return last(curr->right);
}
TreeNode* helper(TreeNode * curr){
    if(curr->left==NULL){
        return curr->right;
    }
    else if(curr->right==NULL){
        return curr->left;
    }
    else {
     TreeNode *f=curr->right;
     TreeNode*h=last(curr->left);
     h->right=f;
     return curr->left;
    }
}
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            return helper(root);
        }
        TreeNode*curr=root;
        while(curr!=NULL){
            if(curr->val>key){
            if(curr->left != NULL && curr->left->val == key){
                  curr->left=helper(curr->left);
                  break;
            }
            else {
                curr=curr->left;
            }
            }
            else{
              if(curr->right != NULL && curr->right->val == key){
                  curr->right=helper(curr->right);
                  break;
            }
            else {
                curr=curr->right;
            }
            }
        }
        return root;
    }
};