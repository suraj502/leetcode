class Solution {
public:
int solve(int i, int j ,vector<int>& nums,vector<vector<int>>&dp){
    if(i>j)return 0;
    if(dp[i][j]!=-1)return dp[i][j];
    int maxi=INT_MIN;
    for(int in=i; in<=j;in++){
        int cost=nums[i-1]*nums[in]*nums[j+1]+solve(in+1,j,nums,dp)+solve(i,in-1,nums,dp);
     maxi=max(maxi,cost);
    }
    return dp[i][j]=maxi;
}
    int maxCoins(vector<int>& nums) {
         int j=nums.size();
        nums.push_back(1);
        nums.insert(nums.begin(),1);
      
       
          vector<vector<int>>dp(j+2,vector<int>(j+2,-1));
      
         return solve(1, j, nums,dp);
    }
};