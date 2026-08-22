class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {

        int mod = 1e9 + 7;

        priority_queue<
            pair<long long, int>,
            vector<pair<long long, int>>,
            greater<pair<long long, int>>
        > pq;

        vector<vector<pair<int, int>>> adj(n);

        for (auto it : roads) {

            int u = it[0];
            int v = it[1];
            int wd = it[2];

            adj[u].push_back({wd, v});
            adj[v].push_back({wd, u});
        }

        vector<long long> dis(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        dis[0] = 0;
        ways[0] = 1;

        pq.push({0, 0});

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            long long wd = it.first;
            int node = it.second;

            // Ignore outdated entry
            if (wd > dis[node])
                continue;

            for (auto adjnode : adj[node]) {

                int newd = adjnode.first;
                int newnode = adjnode.second;

                long long distance = dis[node] + newd;

                if (distance < dis[newnode]) {

                    dis[newnode] = distance;

                    ways[newnode] = ways[node];

                    pq.push({distance, newnode});
                }

                else if (distance == dis[newnode]) {

                    ways[newnode] =
                        (ways[newnode] + ways[node]) % mod;
                }
            }
        }

        return ways[n - 1] % mod;
    }
};