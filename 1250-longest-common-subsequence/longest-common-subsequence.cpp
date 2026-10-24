class Solution {
public:
int solve(int i, int j,  vector<vector<int>>&dp,string &text1, string &text2){
      int n=text1.size();
        int m=text2.size();
// base case 
if(i==n || j==m ){
    return 0;
}
if(dp[i][j]!=-1){
    return dp[i][j];
}
// matched 
if(text1[i]==text2[j]){
    return dp[i][j]=1+solve(i+1,j+1,dp,text1,text2);
}
return dp[i][j]=max(solve(i+1,j,dp,text1,text2),solve(i,j+1,dp,text1,text2));


}
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        return solve(0 , 0, dp,text1,text2);
    }
};