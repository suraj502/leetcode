class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 4>> dp(n + 1);
        vector<vector<int>> ans(n + 1);

        // Store: {left, right, weight, original_index}
        vector<array<long long, 4>> a;

        for (int i = 0; i < n; i++) {
            a.push_back({
                intervals[i][0],
                intervals[i][1],
                intervals[i][2],
                i
            });
        }

        // Sort by starting point
        sort(a.begin(), a.end());

        // next[i] = first interval whose left > a[i].right
        vector<int> next(n);

        for (int i = 0; i < n; i++) {
            int lo = i + 1, hi = n;

            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;

                if (a[mid][0] > a[i][1])
                    hi = mid;
                else
                    lo = mid + 1;
            }

            next[i] = lo;
        }

        // dp[i] = maximum score we can get using intervals from i onward
        // with at most 4 intervals.
        vector<vector<long long>> best(n + 1, vector<long long>(5, 0));
        vector<vector<vector<int>>> res(n + 1,
            vector<vector<int>>(5));

        for (int i = n - 1; i >= 0; i--) {

            for (int k = 1; k <= 4; k++) {

                // Don't take interval i
                best[i][k] = best[i + 1][k];
                res[i][k] = res[i + 1][k];

                // Take interval i
                long long take =
                    a[i][2] + best[next[i]][k - 1];

                vector<int> temp = res[next[i]][k - 1];
                temp.push_back((int)a[i][3]);

                sort(temp.begin(), temp.end());

                if (take > best[i][k] ||
                    (take == best[i][k] && temp < res[i][k])) {

                    best[i][k] = take;
                    res[i][k] = temp;
                }
            }
        }

        return res[0][4];
    }
};