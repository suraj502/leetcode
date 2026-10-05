class Solution {
public:
    int solve(int row, int col, vector<vector<int>>& dp, vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // 1. Out of bounds check must always come first
        if (col < 0 || col >= n) return 1e9; 
        
        // 2. Base case: Reached the last row
        if (row == n - 1) return matrix[row][col];
        
        // 3. Memoization check (using -1e9 as an unvisited flag since values can be negative)
        if (dp[row][col] != -1e9) return dp[row][col];
        
        // 4. Recursive choices
        int a = solve(row + 1, col - 1, dp, matrix);
        int b = solve(row + 1, col, dp, matrix);
        int c = solve(row + 1, col + 1, dp, matrix);
        
        // 5. Store and return
        return dp[row][col] = matrix[row][col] + min(a, min(b, c));
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        // Initialize DP array with a safe flag value like -1e9
        vector<vector<int>> dp(n, vector<int>(n, -1e9));
        
        int ans = INT_MAX;
        for (int i = 0; i < n; i++) {
            int check = solve(0, i, dp, matrix);
            ans = min(ans, check);
        }
        return ans;
    }
};
