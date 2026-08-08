class Solution {
public:

    void dfs(int r, int c, int n, int m, vector<vector<char>>& board) {

        // Outside board
        if (r < 0 || r >= n || c < 0 || c >= m)
            return;

        // Not an O
        if (board[r][c] != 'O')
            return;

        // Mark this O as safe
        board[r][c] = '#';

        // 4 directions
        dfs(r + 1, c, n, m, board);
        dfs(r - 1, c, n, m, board);
        dfs(r, c + 1, n, m, board);
        dfs(r, c - 1, n, m, board);
    }

    void solve(vector<vector<char>>& board) {

        int n = board.size();
        int m = board[0].size();

        // Check first and last row
        for (int c = 0; c < m; c++) {
            dfs(0, c, n, m, board);
            dfs(n - 1, c, n, m, board);
        }

        // Check first and last column
        for (int r = 0; r < n; r++) {
            dfs(r, 0, n, m, board);
            dfs(r, m - 1, n, m, board);
        }

        // Convert surrounded O -> X
        // Convert safe # -> O
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {

                if (board[r][c] == 'O') {
                    board[r][c] = 'X';
                }
                else if (board[r][c] == '#') {
                    board[r][c] = 'O';
                }
            }
        }
    }
};