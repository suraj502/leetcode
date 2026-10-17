class Solution {
public:
    const int INF = 1e9;

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n + 1,
                               vector<int>(amount + 1, INF));

        // Base case
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        for (int i = 1; i <= n; i++) {
            for (int wt = 1; wt <= amount; wt++) {

                // Skip
                int skip = dp[i - 1][wt];

                // Pick
                int pick = INF;

                if (coins[i - 1] <= wt) {
                    pick = 1 + dp[i][wt - coins[i - 1]];
                }

                dp[i][wt] = min(skip, pick);
            }
        }

        return dp[n][amount] >= INF ? -1 : dp[n][amount];
    }
};