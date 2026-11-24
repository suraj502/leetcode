class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int max_len = 0;

        for (int i = 0; i < n; i++) {
            long long pro = 1;
            long long g = nums[i];
            long long lc = nums[i];

            for (int j = i; j < n; j++) {
                pro *= nums[j];
                g = std::__gcd(g, (long long)nums[j]);
                lc = (lc / std::__gcd(lc, (long long)nums[j])) * nums[j];

                // If product matches gcd * lcm, update max length
                if (pro == g * lc) {
                    max_len = max(max_len, j - i + 1);
                } else {
                    // Because all nums[i] >= 1, if product overflows or exceeds g * lc severely, 
                    // we can safely break early to avoid long long overflow.
                    if (pro > 1e12) break; 
                }
            }
        }

        return max_len;
    }
};