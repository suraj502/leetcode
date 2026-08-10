class Solution {
public:
  void dfs(int i, int j, int n, int m,vector<vector<int>>&visited,vector<vector<char>>& grid){
    if(i<0 ||j<0|| i>=n|| j>=m || grid[i][j]=='0'){
        return;
    }
        // 2. Already visited
    if (visited[i][j] == 1)
        return;
    visited[i][j]=1;
    dfs(i+1,j,n,m,visited,grid);
       dfs(i-1,j,n,m,visited,grid);
          dfs(i,j+1,n,m,visited,grid);
             dfs(i,j-1,n,m,visited,grid);

  }

    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int count =0;
      vector<vector<int>> visited(n, vector<int>(m, 0));
      for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]&&grid[i][j]=='1'){
                count++;
                dfs(i,j,n,m,visited,grid);
            }
        }
      }
      return count;
    }
};