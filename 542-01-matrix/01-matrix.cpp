class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n=mat.size();
        int m=mat[0].size();
        vector<vector<int>>visited(n,vector<int>(m,0));
            vector<vector<int>>dis(n,vector<int>(m,0));
            queue<pair<pair<int,int>,int>>q;
            for(int i=0;i<n;i++){
                for(int j=0;j<m;j++){
                    if(mat[i][j]==0){
                        q.push({{i,j},0});
                        visited[i][j]=1;
                     
                    }
                }
            }
            int nrow[]={-1,0,1,0};
            int ncol[]={0,1,0,-1};
            while(!q.empty()){
                int r=q.front().first.first;
                int c=q.front().first.second;
                int time=q.front().second;
                   dis[r][c]=time;
                q.pop();
                for(int i=0;i<4;i++){
                    int nr=r+nrow[i];
                    int nc=c+ncol[i];
                    if(nr>=0 && nr<n && nc>=0 && nc<m &&!visited[nr][nc]){
                         q.push({{nr,nc},time+1});
                         visited[nr][nc]=1;
                    }
                }
            }
            return dis;

    }
};