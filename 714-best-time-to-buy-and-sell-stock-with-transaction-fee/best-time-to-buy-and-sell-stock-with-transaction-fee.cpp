class Solution {
public:
int solve(int days , int buy, vector<vector<int>>&dp,vector<int>& prices, int fee){
        int n=prices.size();
    if(days==n){
        return 0;
    }
    if(dp[days][buy]!=-1)return dp[days][buy];
    //buy
    if(buy==1){
        int bu=-prices[days]+solve(days+1,0,dp,prices,fee);
        int skip=solve(days+1,1,dp,prices,fee);
        dp[days][buy]=max(bu,skip);
    }
    else{
        int skip=prices[days]-fee+solve(days+1,1,dp,prices,fee);
        int hold=solve(days+1,0,dp,prices,fee);
        dp[days][buy]=max(skip,hold);

    }
    return dp[days][buy];
}
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
        return solve(0,1,dp,prices,fee);
    }
};