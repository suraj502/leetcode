class Solution {
public:
    bool dfs(vector<vector<int>>& grid,
             vector<vector<int>>& visited, int i, int j) {

        int n = grid.size();
        int m = grid[0].size();

        if (i < 0 || i >= n || j < 0 || j >= m)
            return false;

        if (grid[i][j] == 1 || visited[i][j])
            return true;

        visited[i][j] = 1;

        bool up = dfs(grid, visited, i - 1, j);
        bool down = dfs(grid, visited, i + 1, j);
        bool left = dfs(grid, visited, i, j - 1);
        bool right = dfs(grid, visited, i, j + 1);

        return up && down && left && right;
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> visited(n, vector<int>(m, 0));
        int ans = 0;

        for (int i = 1; i < n - 1; i++) {
            for (int j = 1; j < m - 1; j++) {
                if (grid[i][j] == 0 && !visited[i][j]) {
                    if (dfs(grid, visited, i, j))
                        ans++;
                }
            }
        }

        return ans;
    }
};