class Solution {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {

        vector<vector<pair<int, int>>> ad(n);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            int wt = it[2];

            ad[u].push_back({v, wt});
        }

        vector<vector<int>> dis(n, vector<int>(k + 1, 1e9));

        // {cost, node, consecutive count}
        priority_queue<
            tuple<int, int, int>,
            vector<tuple<int, int, int>>,
            greater<tuple<int, int, int>>
        > pq;

        dis[0][1] = 0;
        pq.push({0, 0, 1});

        while (!pq.empty()) {

            auto it = pq.top();
            pq.pop();

            int wt = get<0>(it);
            int u = get<1>(it);
            int count = get<2>(it);

            if (wt > dis[u][count]) continue;

            if (u == n - 1) return wt;

            for (auto it : ad[u]) {

                int v = it.first;
                int w = it.second;

                int newCount;

                if (labels[v] == labels[u]) {
                    newCount = count + 1;
                }
                else {
                    newCount = 1;
                }

                if (newCount > k) continue;

                if (wt + w < dis[v][newCount]) {

                    dis[v][newCount] = wt + w;

                    pq.push({wt + w, v, newCount});
                }
            }
        }

        return -1;
    }
};