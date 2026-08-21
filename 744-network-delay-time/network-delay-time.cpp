class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {

        // {time, node}
        priority_queue<pair<int, int>,
                       vector<pair<int, int>>,
                       greater<pair<int, int>>> pq;

        vector<vector<pair<int, int>>> adj(n + 1);

        // Create adjacency list
        for (auto it : times) {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v, w});
        }

        vector<bool> visited(n + 1, false);

        int cnt = 0;
        int mintime = 0;

        // {time, starting node}
        pq.push({0, k});

        while (!pq.empty()) {

            auto [wd, node] = pq.top();
            pq.pop();

            // Already processed this node
            if (visited[node])
                continue;

            // First time we process this node
            visited[node] = true;
            cnt++;

            // Maximum time required
            mintime = max(mintime, wd);

            // Visit neighbours
            for (auto it : adj[node]) {

                int v = it.first;
                int wt = it.second;

                if (!visited[v]) {
                    pq.push({wd + wt, v});
                }
            }
        }

        // Not all nodes were reached
        if (cnt != n)
            return -1;

        return mintime;
    }
};