#include <vector>
#include <algorithm>

class Solution {
public:
    int maxSum(std::vector<int>& nums, int k) {
        long long MOD = 1e9 + 7;
        
        // Count the frequency of each bit set across all numbers
        std::vector<int> bit_counts(30, 0);
        for (int x : nums) {
            for (int b = 0; b < 30; ++b) {
                if ((x >> b) & 1) {
                    bit_counts[b]++;
                }
            }
        }
        
        // Build the k largest possible numbers
        std::vector<long long> max_nums(k, 0);
        for (int b = 29; b >= 0; --b) {
            int count = bit_counts[b];
            // Distribute the available set bits to at most k numbers
            int limit = std::min(count, k);
            for (int i = 0; i < limit; ++i) {
                max_nums[i] |= (1LL << b);
            }
        }
        
        // Calculate the sum of squares modulo 10^9 + 7
        long long total_sum = 0;
        for (long long x : max_nums) {
            total_sum = (total_sum + (x * x) % MOD) % MOD;
        }
        
        return total_sum;
    }
};