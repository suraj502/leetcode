class Solution {
public:

    int dfs(int node, int color, vector<int>& visited,
            vector<int>& colour, vector<vector<int>>& graph) {

        visited[node] = 1;
        colour[node] = color;

        for (auto it : graph[node]) {

            if (!visited[it]) {
                if (dfs(it, !color, visited, colour, graph) == 0)
                    return 0;
            }
            else if (colour[it] == colour[node]) {
                return 0;
            }
        }

        return 1;
    }

    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();

        vector<int> visited(n, 0);
        vector<int> colour(n, -1);

        for (int i = 0; i < n; i++) {

            if (!visited[i]) {

                if (dfs(i, 0, visited, colour, graph) == 0)
                    return false;
            }
        }

        return true;
    }
};