
class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
        vector<int> dp(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            int one = INT_MAX;
            int two = INT_MAX;
            int three = INT_MAX;

            if (i - 1 >= 0) {
                one = dp[i - 1] + costs[i - 1] + 1;
            }

            if (i - 2 >= 0) {
                two = dp[i - 2] + costs[i - 1] + 4;
            }

            if (i - 3 >= 0) {
                three = dp[i - 3] + costs[i - 1] + 9;
            }

            dp[i] = min({one, two, three});
        }

        return dp[n];
    }
};
