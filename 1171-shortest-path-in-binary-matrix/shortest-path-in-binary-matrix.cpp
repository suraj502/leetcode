class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
       // Start or destination is blocked
        if (grid[0][0] == 1 || grid[n - 1][n - 1] == 1) {
            return -1;
        }

        int dr[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[] = {-1,  0,  1,-1, 1,-1, 0, 1};
vector<vector<int>> dist(n, vector<int>(m, 1e9));
queue<pair<pair<int,int>, int>> q;
        q.push({{0,0},1});
        while(!q.empty()){
         auto [position, d] = q.front();
            q.pop();

            int row = position.first;
            int col = position.second;

            // Reached destination
            if (row == n - 1 && col == m - 1) {
                return d;
            }
          for (int i=0;i<8;i++){
           
                int nrow = row + dr[i];
                int ncol = col + dc[i];
            if(nrow<0 || nrow>=n||ncol>=m ||ncol<0 || grid[nrow][ncol]==1  ) continue ;
            
                if (d + 1 < dist[nrow][ncol]) {

                    dist[nrow][ncol] = d + 1;

                    q.push({{nrow, ncol}, d + 1});
                }

          }
        }
        return -1;
    }
};