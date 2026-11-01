class Solution {
public:
    int solve(int i, int j, vector<vector<int>>& dp,
              string& s, string& p) {

        int n = s.size();
        int m = p.size();

        // Both exhausted
        if (i == n && j == m)
            return 1;

        // Pattern exhausted
        if (j == m)
            return 0;

        // String exhausted
        if (i == n) {
            while (j < m) {
                if (p[j] != '*')
                    return dp[i][j] = 0;
                j++;
            }
            return dp[i][m] = 1;
        }

        if (dp[i][j] != -1)
            return dp[i][j];

        // Matching character or ?
        if (s[i] == p[j] || p[j] == '?') {
            return dp[i][j] =
                solve(i + 1, j + 1, dp, s, p);
        }

        // Star
        else if (p[j] == '*') {
            return dp[i][j] =
                solve(i + 1, j, dp, s, p) ||
                solve(i, j + 1, dp, s, p);
        }

        // Characters don't match
        else {
            return dp[i][j] = 0;
        }
    }

    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();

        vector<vector<int>> dp(
            n + 1, vector<int>(m + 1, -1)
        );

        return solve(0, 0, dp, s, p);
    }
};