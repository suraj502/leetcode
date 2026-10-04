class Solution {
public:
  void solve(int index,int k,   set<vector<int>>&st,vector<int>&curr,int n){
  if(curr.size()==k){
  st.insert(curr);
    return ;
  }
for(int i=index; i<=n; i++){
    curr.push_back(i);
    solve(i+1, k, st, curr, n);
    curr.pop_back();
}

  }

    vector<vector<int>> combine(int n, int k) {
       set<vector<int>> st; 
        vector<vector<int>>ans;
        vector<int>curr;
        solve(1,k,st,curr,n);
        for(auto it:st){
            ans.push_back(it);
        }
        return ans;
    }
};