class Solution {
public:

    int solve(vector<int>& nums, vector<int>& dp, int index, int n) {

        // Base condition
        if (index >= n)
            return 0;

        // Already calculated
        if (dp[index] != -1)
            return dp[index];

        // Pick
        int pick = nums[index] + solve(nums, dp, index + 2, n);

        // Skip
        int skip = solve(nums, dp, index + 1, n);

        return dp[index] = max(pick, skip);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();

        if (n == 1)
            return nums[0];

        // Case 1: Don't take first house
        vector<int> dp1(n, -1);
        int case1 = solve(nums, dp1, 1, n);

        // Case 2: Don't take last house
        vector<int> dp2(n, -1);
        int case2 = solve(nums, dp2, 0, n - 1);

        return max(case1, case2);
    }
};