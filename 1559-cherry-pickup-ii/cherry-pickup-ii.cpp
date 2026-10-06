class Solution {
public:

    int solve(int row, int col1, int col2,
              vector<vector<vector<int>>>& dp,
              vector<vector<int>>& grid) {

        int cols = grid[0].size();
        int n = grid.size();

        // Out of bounds
        if (col1 < 0 || col1 >= cols ||
            col2 < 0 || col2 >= cols)
            return -1e9;

        // Already calculated
        if (dp[row][col1][col2] != -1)
            return dp[row][col1][col2];

        // Current cherries
        int cherries;

        if (col1 == col2)
            cherries = grid[row][col1];
        else
            cherries = grid[row][col1] + grid[row][col2];

        // Last row
        if (row == n - 1)
            return dp[row][col1][col2] = cherries;

        int ans = -1e9;

        // Robot 1: -1, 0, +1
        // Robot 2: -1, 0, +1

        for (int move1 = -1; move1 <= 1; move1++) {

            for (int move2 = -1; move2 <= 1; move2++) {

                int nextCol1 = col1 + move1;
                int nextCol2 = col2 + move2;

                ans = max(ans,
                    solve(row + 1,
                          nextCol1,
                          nextCol2,
                          dp,
                          grid));
            }
        }

        return dp[row][col1][col2] = cherries + ans;
    }

    int cherryPickup(vector<vector<int>>& grid) {

        int rows = grid.size();
        int cols = grid[0].size();

        vector<vector<vector<int>>> dp(
            rows,
            vector<vector<int>>(
                cols,
                vector<int>(cols, -1)
            )
        );

        return solve(0, 0, cols - 1, dp, grid);
    }
};