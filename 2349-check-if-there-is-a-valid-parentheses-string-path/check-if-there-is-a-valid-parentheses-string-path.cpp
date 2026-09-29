class Solution {
public:

    bool solve(vector<vector<char>>& grid, int r, int c, int balance,
               vector<vector<vector<int>>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        if (r >= n || c >= m)
            return false;

        if (grid[r][c] == '(')
            balance++;
        else
            balance--;

        if (balance < 0)
            return false;

        if (dp[r][c][balance] != -1)
            return dp[r][c][balance];

        if (r == n - 1 && c == m - 1)
            return dp[r][c][balance] = (balance == 0);

        bool ans =
            solve(grid, r + 1, c, balance, dp) ||
            solve(grid, r, c + 1, balance, dp);

        return dp[r][c][balance] = ans;
    }

    bool hasValidPath(vector<vector<char>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

        if (grid[0][0] == ')')
            return false;

        if ((n + m - 1) % 2 != 0)
            return false;

        vector<vector<vector<int>>> dp(
            n,
            vector<vector<int>>(
                m,
                vector<int>(n + m + 1, -1)
            )
        );

        return solve(grid, 0, 0, 0, dp);
    }
};