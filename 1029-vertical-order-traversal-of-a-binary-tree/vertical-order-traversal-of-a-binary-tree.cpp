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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        vector<vector<int>>ans;
        queue<pair<TreeNode*,pair<int,int>>>todo;
        todo.push({root,{0,0}});
        while(!todo.empty()){
  auto p=todo.front();
            todo.pop();
                 TreeNode*x=p.first;
            auto row=p.second.first;
            auto col=p.second.second;
            mp[col][row].insert(x->val);
            if(x->left!=NULL){
                todo.push({x->left,{row+1,col-1}});
            }
             if(x->right!=NULL){
                todo.push({x->right,{row+1,col+1}});
            }

        }
         for (auto &col : mp) {

    vector<int> temp;

    for (auto &row : col.second) {

        for (int value : row.second) {

            temp.push_back(value);

        }
    }

    ans.push_back(temp);
}

return ans;
    }
   
};