class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>,
                       greater<tuple<int, int, int>>>
            pq;
        int n = grid.size();

        vector<vector<int>> visited(n, vector<int>(n, 0));
        int row[] = {0, 1, 0, -1};
        int col[] = {-1, 0, 1, 0};
        pq.push({grid[0][0],0,0});
        visited[0][0]=1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            auto [elv, r, c] = it;
            if(r==n-1 && c==n-1)return elv;
            for(int i=0;i<4;i++){
                int nrow=row[i]+r;
                int ncol=col[i]+c;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<n && !visited[nrow][ncol]){
                    pq.push({max(elv,grid[nrow][ncol]),nrow,ncol});
                    visited[nrow][ncol]=1;
                }
            }
        }
        return -1;
    }
};