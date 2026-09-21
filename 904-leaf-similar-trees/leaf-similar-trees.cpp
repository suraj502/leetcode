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

  void dfs(TreeNode* root, vector<int>& r) {

        if(root == NULL)
            return;

        // leaf node
        if(root->left == NULL && root->right == NULL) {
            r.push_back(root->val);
            return;
        }

        dfs(root->left, r);
        dfs(root->right, r);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>r1,r2;
        // traverse r1
     dfs(root1,r1);
     dfs(root2,r2);
     int n=r1.size(); int m=r2.size();
     if(n!=m)return false;
     int i=0,j=0;
     while(i<n && j<m){
        if(r1[i]!=r2[j])return false;
        i++;
        j++;
     }
     return true;
    }
};