
class Solution {
public:
    int solve(int index, int prev, vector<int>& nums,
              vector<vector<int>>& dp) {
        int n = nums.size();

        if (index == n) {
            return 0;
        }

        if (dp[index][prev + 1] != -1) {
            return dp[index][prev + 1];
        }

        // Not pick
        int nopick = solve(index + 1, prev, nums, dp);

        // Pick
        int pick = 0;
        if (prev == -1 || nums[index] > nums[prev]) {
            pick = 1 + solve(index + 1, index, nums, dp);
        }

        return dp[index][prev + 1] = max(pick, nopick);
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));

        return solve(0, -1, nums, dp);
    }
};
