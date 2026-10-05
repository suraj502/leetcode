class Solution {
public:
  int solve(int row, int col,vector<vector<int>>&dp,vector<vector<int>>& triangle){
    int n=triangle.size();
// base case 
if (row == n - 1) {
            return triangle[row][col];
        }


if(dp[row][col]!=1e9+7)return dp[row][col];
int a=solve(row+1,col,dp,triangle);
int b=solve(row+1,col+1,dp,triangle);
   dp[row][col]=triangle[row][col] +min(a,b);
   return dp[row][col];

  }

    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        if(n==1)return triangle[0][0];
        vector<vector<int>>dp(n+1,vector<int>(n+1,1e9+7));
        int ans=solve(0,0,dp,triangle);
        return ans;
    }
};