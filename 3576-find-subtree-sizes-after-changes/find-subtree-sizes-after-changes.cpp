class Solution {
public:
    vector<int> answer;
    vector<vector<int>> adj, finalTree;
    vector<int> parent;

    void dfs1(int node, vector<int>& last) {
        int ch = s[node] - 'a';

        int prev = last[ch];

        if (node != 0 && prev != -1) {
            parent[node] = prev;
        }

        last[ch] = node;

        for (int child : adj[node]) {
            dfs1(child, last);
        }

        last[ch] = prev;
    }

    string s;

    void dfs2(int node) {
        answer[node] = 1;

        for (int child : finalTree[node]) {
            dfs2(child);
            answer[node] += answer[child];
        }
    }

    vector<int> findSubtreeSizes(vector<int>& p, string str) {
        int n = p.size();

        s = str;
        parent = p;
        adj.resize(n);
        finalTree.resize(n);
        answer.resize(n);

        // Build original tree
        for (int i = 1; i < n; i++) {
            adj[p[i]].push_back(i);
        }

        // Find new parents using original tree
        vector<int> last(26, -1);
        dfs1(0, last);

        // Build final tree
        for (int i = 1; i < n; i++) {
            finalTree[parent[i]].push_back(i);
        }

        // Calculate subtree sizes
        dfs2(0);

        return answer;
    }
};