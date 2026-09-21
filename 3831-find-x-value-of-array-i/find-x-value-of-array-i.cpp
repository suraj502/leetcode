class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        
        vector<long long> ans(k, 0);
        
        // prev[r] = number of subarrays ending at previous index
        // whose product % k == r
        vector<long long> prev(k, 0);

        for (int num : nums) {
            
            vector<long long> curr(k, 0);

            int rem = num % k;

            // Start a new subarray with nums[i]
            curr[rem]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int newRem = (r * rem) % k;
                curr[newRem] += prev[r];
            }

            // Add all subarrays ending at current index
            for (int r = 0; r < k; r++) {
                ans[r] += curr[r];
            }

            prev = curr;
        }

        return ans;
    }
};