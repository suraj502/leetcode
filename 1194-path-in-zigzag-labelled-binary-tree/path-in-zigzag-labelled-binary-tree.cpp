class Solution {
public:
    void solve(int label, vector<int>& ans) {
        ans.push_back(label);

        if (label == 1)
            return;

        int row = floor(log2(label)) + 1;

        int start = pow(2, row - 1);
        int end = pow(2, row) - 1;

        int parent;

        if (row % 2 == 0) {
            // Current row is reversed
            int diff = end - label;

            parent = start / 2 + diff / 2;
        }
        else {
            // Current row is normal
            int diff = label - start;

            parent = end / 2 - diff / 2;
        }

        solve(parent, ans);
    }

    vector<int> pathInZigZagTree(int label) {
        vector<int> ans;

        solve(label, ans);

        reverse(ans.begin(), ans.end());

        return ans;
    }
};