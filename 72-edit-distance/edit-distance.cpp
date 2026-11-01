class Solution {
public:
    int solve(int i, int j, string &s, string &t,
              vector<vector<int>>& dp) {

        int n = s.size();
        int m = t.size();

        // Base conditions
        if (j == m) return n - i;
        if (i == n) return m - j;

        if (dp[i][j] != -1)
            return dp[i][j];

        // Characters match
        if (s[i] == t[j]) {
            return dp[i][j] =
                solve(i + 1, j + 1, s, t, dp);
        }

        // Three operations
        int del = solve(i + 1, j, s, t, dp);
        int ins = solve(i, j + 1, s, t, dp);
        int rep = solve(i + 1, j + 1, s, t, dp);

        return dp[i][j] = 1 + min({del, ins, rep});
    }

    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(
            n + 1, vector<int>(m + 1, -1)
        );

        return solve(0, 0, word1, word2, dp);
    }
};