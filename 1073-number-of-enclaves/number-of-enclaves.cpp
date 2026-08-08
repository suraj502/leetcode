class Solution {
public:
    void dfs(int r,int n, int m, int c, vector<vector<int>>&visited,vector<vector<int>>& grid){
     if(r<0 || r>=n || c<0 || c>=m || grid[r][c]!=1|| visited[r][c])return;
     visited[r][c]=1;
     dfs(r+1,n,m,c,visited,grid);
      dfs(r-1,n,m,c,visited,grid);
       dfs(r,n,m,c+1,visited,grid);
        dfs(r,n,m,c-1,visited,grid);



    }


    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size(); int count =0;
        vector<vector<int>>visited(n,vector<int>(m,0));
        //check for the rows 
        for(int i=0;i<m;i++){
            if(grid[0][i]==1){
                dfs(0,n,m,i,visited,grid);
            }
            if(grid[n-1][i]==1){
               dfs(n-1,n,m,i,visited,grid); 
            }
        }
        //check for col
        for(int i=0;i<n;i++){
            if(grid[i][0]==1){
                dfs(i,n,m,0,visited,grid);
            }
            if(grid[i][m-1]==1){
                dfs(i,n,m,m-1,visited,grid);
            }
        }
     for(int i=0; i<n;i++){
        for (int j=0;j<m;j++){
            if(!visited[i][j]&&grid[i][j]==1){
    count++ ;
            }
     }
     }
     return count;
    }
};