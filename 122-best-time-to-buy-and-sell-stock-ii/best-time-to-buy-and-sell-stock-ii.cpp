class Solution {
public:
  int solve(int days,int buy ,vector<vector<int>>&dp,vector<int>&prices){
   //
   int n=prices.size();
     if(days==n)return 0;
     if(dp[days][buy]!=-1){
        return dp[days][buy];
     }
     int maxi;
     if(buy==1){
  int bu=-prices[days]+solve(days+1,0,dp,prices);
  int skip=solve(days+1,1,dp,prices);
maxi=max(bu,skip);
     }
     //
     else{
     int sell=prices[days]+solve(days+1,1,dp,prices);
     int hold =solve(days+1,0,dp,prices);
     maxi=max(sell,hold);
    
     }
      dp[days][buy]=maxi;
     return dp[days][buy];
}
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>>dp(n+1,vector<int>(2,-1));
     return  solve(0,1,dp,prices);

    }
};


/* 
can buy =1 two part can take or not 
can buy the stlk 
cannot buy the stalk 
can buy =0 two part cannot take 
it has it can sell 
or it will not sell

*/