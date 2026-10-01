class Solution {
public:
int solve(vector<int>&nums,vector<int>&dp,int index, int n){
// base codnition
if(index>=n){
    return 0;
}
// checking 
if(dp[index]!=-1)return dp[index];
// pick the current nd move to i+2;
int pick=nums[index]+solve(nums,dp,index+2,n);
// skip curent and move to second 
int skip=solve(nums,dp,index+1,n);
dp[index]=max(pick,skip);
return dp[index];


}
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int>dp(n+1,-1);
       return solve(nums,dp,0,n);

    }
};