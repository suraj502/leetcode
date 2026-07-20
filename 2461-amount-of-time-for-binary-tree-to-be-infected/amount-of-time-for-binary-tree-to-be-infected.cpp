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
void parent(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&mp,int start,TreeNode*&target){
  if(root==NULL)return ;
  queue<TreeNode*>q;
  q.push(root);
  while(!q.empty()){
    auto a =q.front();
    q.pop();
    if(a->val==start){
        target=a;
    }
    if(a->left!=NULL){
        mp[a->left]=a;
        q.push(a->left);
    }
     if(a->right!=NULL){
        mp[a->right]=a;
        q.push(a->right);
    }

  }

}
        void infection(TreeNode*root,unordered_map<TreeNode*,TreeNode*>&mp,TreeNode*target,int&cnt){
         unordered_set<TreeNode*> visited;
         queue<TreeNode*>q;
           q.push(target);
           visited.insert(target);
           while(!q.empty()){
            int size=q.size();
                 bool flag=false;
            for(int i=0;i<size;i++){
            auto a=q.front();
            q.pop();
       
            if(a->left!=NULL && !visited.count(a->left)){
                q.push(a->left);
                visited.insert(a->left);
                flag=true;
            }
             if(a->right!=NULL && !visited.count(a->right)){
                q.push(a->right);
                visited.insert(a->right);
                flag=true;
            }
            if(mp.count(a)&&!visited.count(mp[a])){
                q.push(mp[a]);
                visited.insert(mp[a]);
                flag =true;
            }
          
            
            }
              if (flag)
        cnt++;
           }
        }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<TreeNode*,TreeNode*>mp; int cnt=0;
        TreeNode*target;
        //find parents 
        parent(root,mp,start,target);
infection(root,mp,target,cnt);
return cnt;
    }
};