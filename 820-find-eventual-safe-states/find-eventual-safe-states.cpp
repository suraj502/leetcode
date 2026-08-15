class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        // 1. Reverse the graph
        vector<vector<int>> reverseGraph(n);

        // indegree in reversed graph
        vector<int> indegree(n, 0);

        for (int u = 0; u < n; u++) {
            for (int v : graph[u]) {
                // Original: u -> v
                // Reverse:  v -> u
                reverseGraph[v].push_back(u);

                // In reversed graph, v -> u
                // so indegree[u] increases
                indegree[u]++;
            }
        }

        // 2. Put terminal nodes into queue
        // Terminal node has original outdegree = 0
        // Therefore its indegree in reversed graph = 0
        queue<int> q;

        for (int i = 0; i < n; i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        // 3. BFS / Topological Sort
        vector<int> safe;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            safe.push_back(node);

            // Find nodes that point to 'node'
            // in the original graph
            for (int prev : reverseGraph[node]) {

                // One outgoing edge of prev
                // has now been proven safe
                indegree[prev]--;

                // ALL outgoing edges of prev are safe
                if (indegree[prev] == 0) {
                    q.push(prev);
                }
            }
        }

        // 4. Problem asks for ascending order
        sort(safe.begin(), safe.end());

        return safe;
    }
};