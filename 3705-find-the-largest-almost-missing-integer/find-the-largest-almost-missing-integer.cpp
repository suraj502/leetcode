#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> subarray_counts; // Tracks how many subarrays each number appears in
        
        // 1. Loop through every starting position of a subarray of size k
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> unique_in_subarray;
            
            // 2. Collect all unique elements in the current subarray
            for (int j = i; j < i + k; j++) {
                unique_in_subarray.insert(nums[j]);
            }
            
            // 3. Increment the subarray count for each element found
            for (int num : unique_in_subarray) {
                subarray_counts[num]++;
            }
        }
        
        // 4. Find the largest integer that appeared in exactly 1 subarray
        int ans = -1;
        for (auto& pair : subarray_counts) {
            if (pair.second == 1) {
                ans = max(ans, pair.first);
            }
        }
        
        return ans;
    }
};
