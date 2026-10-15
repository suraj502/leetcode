class Solution {
public:
int solve (int i,vector<int>&nums,vector<vector<int>>&dp, int nt){
  // base cond
  int n=nums.size();
  if(i==n){
    return nt==0;
  }
  
  if(dp[i][nt]!=-1)return dp[i][nt];
  // skip 
  int skip =solve(i+1,nums,dp,nt);
  // pick
  int pick=0;
  if(nums[i]<=nt){
    pick= solve(i+1, nums, dp, nt-nums[i]);
  }
dp[i][nt]=skip + pick;
return dp[i][nt];

}
    int findTargetSumWays(vector<int>& nums, int target) {
        int total=0;
        int n=nums.size();
        for(auto it :nums)total+=it;
          if (abs(target) > total) return 0;
        if ((total + target) % 2 != 0) return 0;
        int nt=(total+target)/2;
        vector<vector<int>>dp(n+1,vector<int>(nt+1,-1));
        return solve(0,nums,dp,nt);
    }
};