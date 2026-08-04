class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        int drow[4]={-1,0,1,0};
        int dcol[4]={0,1,0,-1}; int days=0; int cnt=0; int total=0;
vector<vector<int>> vis(n, vector<int>(m, 0));
        queue<pair<pair<int,int>,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
      if(grid[i][j]!=0){
        cnt+=1;
      }
      if(grid[i][j]==2){
        q.push({{i,j},0});
        vis[i][j]=2;
      }
            }}
            int tm=0;
            // next step;
            while(!q.empty()){
                int k=q.size();
   total+=k;
                while(k--){
          int row=q.front().first.first;
          int col=q.front().first.second;
          int time=q.front().second;
          q.pop();
          tm=max(tm,time);
          for(int i=0;i<4;i++){
            int nrow=row+drow[i];
              int ncol=col+dcol[i];
              if(nrow>=0&&nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol]==1 &&vis[nrow][ncol]!=2){
                q.push({{nrow,ncol},time+1});
                vis[nrow][ncol]=2;
              }
              
          }
                }
              
        }
          //
            if(total==cnt){
                return tm;
            }
            else{
                return -1;
            }
    }
};