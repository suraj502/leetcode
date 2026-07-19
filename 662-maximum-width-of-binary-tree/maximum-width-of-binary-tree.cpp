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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxi=0;
        if(root == NULL)
            return 0;

        queue<pair<TreeNode*,long long >>q;
        long long first,last;
        q.push({root,0});
        while(!q.empty()){
int size=q.size();
long long m=q.front().second;

for(int i=0;i<size;i++){
TreeNode*a=q.front().first;
long long ans=q.front().second;
q.pop();
long long index=ans-m;
if(i==0){
    first=index;
}
if(i==size-1){
    last=index;
}

if(a->left!=NULL){
    q.push({a->left,2*index+1});
}
if(a->right!=NULL){
    q.push({a->right,2*index+2});
}

}
maxi=max(maxi,last-first+1);
        }
       return (int)maxi; 
    }
};