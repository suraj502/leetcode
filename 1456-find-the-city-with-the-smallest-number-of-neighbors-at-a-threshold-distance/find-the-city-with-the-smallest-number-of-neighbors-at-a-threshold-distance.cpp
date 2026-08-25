class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
       
        // distance vector 
       vector<vector<int>> distance(n, vector<int>(n, 1e9));
         for(int i = 0; i < n; i++) {
            distance[i][i] = 0;
        }
        for(auto it :edges){
            int u=it[0];
            int v=it[1];
            int wt=it[2];
            distance[u][v]=wt;
            distance[v][u]=wt;
        }
     for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(distance[i][j]>distance[i][k]+distance[k][j]){
                   distance[i][j]=distance[i][k]+distance[k][j];
                    }
                }
            }
        }
         int mini = INT_MAX;
        int ans = -1;

        // Count reachable cities
        for(int i = 0; i < n; i++) {
            int counter = 0;

            for(int j = 0; j < n; j++) {
                if(distance[i][j] <= distanceThreshold) {
                    counter++;
                }
            }

            if(counter <= mini) {
                mini = counter;
                ans = i;
            }
        }
      return ans;
    }
};