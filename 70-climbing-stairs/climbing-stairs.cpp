class Solution {
public:
  int solve(int n,vector<int>&dp){
    if(n==0)return 1;
    if(n<0)return 0;
if(dp[n]!=-1)return dp[n];

int onestep=solve(n-1,dp);
int twostep=solve(n-2,dp);
int ans=onestep+twostep;
dp[n]=ans;
return ans;
   
  }
    int climbStairs(int n) {
        /* 
        we can 1 or 2 
        -1
        -2
  */
  vector<int>dp(n+1,-1);
return solve(n,dp);

    }
};