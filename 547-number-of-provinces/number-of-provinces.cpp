class Solution {
public:
    void dfs(int node, vector<int> adjList[], vector<int>& vis) {
        vis[node] = 1;

        for (int it : adjList[node]) {
            if (!vis[it]) {
                dfs(it, adjList, vis);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& adj) {

        int n = adj.size();

        vector<int> adjList[n];

        // Matrix -> Adjacency List
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {

                if (adj[i][j] == 1 && i != j) {
                    adjList[i].push_back(j);
                }

            }
        }

        vector<int> vis(n, 0);

        int count = 0;

        for (int i = 0; i < n; i++) {

            if (!vis[i]) {
                dfs(i, adjList, vis);
                count++;
            }

        }

        return count;
    }
};