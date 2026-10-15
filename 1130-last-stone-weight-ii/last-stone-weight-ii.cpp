
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int total = 0;

        for (int x : stones) {
            total += x;
        }

        int target = total / 2;

        vector<vector<bool>> dp(
            n + 1, vector<bool>(target + 1, false)
        );

        // Sum 0 is possible using any number of elements.
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }

        for (int i = 1; i <= n; i++) {
            for (int sum = 1; sum <= target; sum++) {
                // Skip the current stone.
                dp[i][sum] = dp[i - 1][sum];

                // Pick the current stone.
                if (stones[i - 1] <= sum) {
                    dp[i][sum] = dp[i][sum] ||
                        dp[i - 1][sum - stones[i - 1]];
                }
            }
        }
int mini=1e9;
for(int i=0; i<=total/2;i++){
    if(dp[n][i]==true){
        mini=min(mini,abs((total-i)-i));
    }
}
return mini;
      
    }
};

