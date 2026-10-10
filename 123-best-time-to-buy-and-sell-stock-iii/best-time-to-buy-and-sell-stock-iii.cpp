
class Solution {
public:
    int solve(int days, int avl, vector<int>& price,
              int trans, vector<vector<vector<int>>>& dp) {

        int n = price.size();

        if (days == n || trans == 0)
            return 0;

        if (dp[days][avl][trans] != -1)
            return dp[days][avl][trans];

        if (avl == 1) {
            int buy = -price[days] +
                      solve(days + 1, 0, price, trans, dp);

            int skip = solve(days + 1, 1, price, trans, dp);

            dp[days][avl][trans] = max(buy, skip);
        }
        else {
            int sell = price[days] +
                       solve(days + 1, 1, price, trans - 1, dp);

            int hold = solve(days + 1, 0, price, trans, dp);

            dp[days][avl][trans] = max(sell, hold);
        }

        return dp[days][avl][trans];
    }

    int maxProfit(vector<int>& price) {
        int n = price.size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(2, vector<int>(3, -1))
        );

        return solve(0, 1, price, 2, dp);
    }
};
