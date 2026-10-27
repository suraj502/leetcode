class Solution {
public:
    int solve(string &s, int i, int j,vector<vector<int>>&dp) {
        // Base case: 1 character left
        if (i == j) return 1;
        // Base case: empty window
        if (i > j) return 0;
        if(dp[i][j]!=-1)return dp[i][j];
        // If characters match, they contribute 2 to the palindrome length
        if (s[i] == s[j]) {
            dp[i][j]=2 + solve(s, i + 1, j - 1,dp);
            return dp[i][j];
        }
        
        // Otherwise, try excluding either the left or the right character
        dp[i][j]=max(solve(s, i + 1, j,dp), solve(s, i, j - 1,dp));
        return dp[i][j];
    }

    int longestPalindromeSubseq(string s) {
        int n=s.size();
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
        return solve(s, 0, s.size() - 1,dp);
    }
};