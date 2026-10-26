class Solution {
public:
    long long solve(int row, int col, vector<vector<int>>& grid, vector<vector<int>>& visited) {
        int n = grid.size();
        int m = grid[0].size();
        
        // Fixed boundary check using 'm' for columns
        if (row < 0 || row >= n || col < 0 || col >= m) return 0;
        
        // Base case: if water (0) or already visited
        if (grid[row][col] == 0 || visited[row][col] != 0) return 0;
        
        visited[row][col] = 1;
        
        // Use long long for sum to prevent integer overflow
        long long sum = grid[row][col] 
                      + solve(row - 1, col, grid, visited)
                      + solve(row + 1, col, grid, visited)
                      + solve(row, col + 1, grid, visited)
                      + solve(row, col - 1, grid, visited);
                      
        return sum;
    }

    int countIslands(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] > 0 && !visited[i][j]) {
                    long long totalValue = solve(i, j, grid, visited);
                    if (totalValue % k == 0) {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};