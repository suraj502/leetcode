class Solution {
public:
 int solve(string &s , int i, int j, vector<vector<int>>&dp ){
// base cond
if(i==j)return 1;
 if (i > j) return 0;
// if match
if(dp[i][j]!=-1)return dp[i][j];
if(s[i]==s[j]){
   dp[i][j]= 2+solve(s,i+1,j-1,dp);
   return dp[i][j];
}
dp[i][j]=max(solve(s,i+1,j,dp),solve(s,i,j-1,dp));
return dp[i][j];



 }

    int minInsertions(string s) {
        int n=s.length();
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
      int lg=  solve(s,0,n-1,dp);
      return n-lg;
    }
};