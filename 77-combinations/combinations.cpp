class Solution {
public:
  void solve(int index,int k,   vector<int>&curr,int n, vector<vector<int>>&ans){
  if(curr.size()==k){
  ans.push_back(curr);
    return ;
  }
for(int i=index; i<=n; i++){
    curr.push_back(i);
    solve(i+1, k,  curr, n,ans);
    curr.pop_back();
}

  }

    vector<vector<int>> combine(int n, int k) {
      
        vector<vector<int>>ans;
        vector<int>curr;
        solve(1,k,curr,n,ans);
      
        return ans;
    }
};