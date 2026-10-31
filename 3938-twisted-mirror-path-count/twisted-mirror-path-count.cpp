class Solution {
public:
    const int MOD = 1e9 + 7;

    int solve(int i, int j, vector<vector<int>>& grid,
              vector<vector<int>>& dp) {

        int n = grid.size();
        int m = grid[0].size();

        if (i >= n || j >= m) return 0;

        if (i == n-1 && j == m-1) return 1;

        if (dp[i][j] != -1) return dp[i][j];

        // Right
        int x = i, y = j+1;
        bool moveDown = true;

        while (x < n && y < m && grid[x][y] == 1) {
            if (moveDown) {
                x++;
            } else {
                y++;
            }
            moveDown = !moveDown;
        }

        int right = solve(x, y, grid, dp);

        // Down
        x = i+1, y = j;
        bool moveRight = true;

        while (x < n && y < m && grid[x][y] == 1) {
            if (moveRight) {
                y++;
            } else {
                x++;
            }
            moveRight = !moveRight;
        }

        int down = solve(x, y, grid, dp);

        return dp[i][j] = (right + down) % MOD;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dp(n, vector<int>(m, -1));

        return solve(0, 0, grid, dp);
    }
};