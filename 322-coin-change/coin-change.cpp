class Solution {
public:
    int solve(int index, vector<int>& coins,
              vector<vector<int>>& dp, int amount) {
        int n = coins.size();

        if (amount == 0) return 0;
        if (index == n) return 1e9;

        if (dp[index][amount] != -1)
            return dp[index][amount];

        int ans = solve(index + 1, coins, dp, amount); // Skip

        if (coins[index] <= amount) {
            int pick = 1 + solve(index, coins, dp,
                                 amount - coins[index]);
            ans = min(ans, pick);
        }

        return dp[index][amount] = ans;
    }

    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();

        vector<vector<int>> dp(n, vector<int>(amount + 1, -1));

        int ans = solve(0, coins, dp, amount);

        if (ans >= 1e9) return -1;
        return ans;
    }
};