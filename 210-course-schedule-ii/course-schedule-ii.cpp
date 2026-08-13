class Solution {
public:
    bool dfs(int node, vector<int>& visited, stack<int>& st,
             vector<vector<int>>& adj) {

        // 1 = currently visiting
        // 2 = completely visited

        visited[node] = 1;

        for (auto it : adj[node]) {

            if (visited[it] == 1) {
                // Cycle detected
                return false;
            }

            if (visited[it] == 0) {
                if (!dfs(it, visited, st, adj)) {
                    return false;
                }
            }
        }

        visited[node] = 2;
        st.push(node);

        return true;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        stack<int> st;
        vector<int> ans;

        vector<vector<int>> adj(numCourses);

        // prerequisite [u, v]
        // v -> u
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];

            adj[v].push_back(u);
        }

        vector<int> visited(numCourses, 0);

        for (int i = 0; i < numCourses; i++) {

            if (visited[i] == 0) {

                if (!dfs(i, visited, st, adj)) {
                    return {};
                }
            }
        }

        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }
};