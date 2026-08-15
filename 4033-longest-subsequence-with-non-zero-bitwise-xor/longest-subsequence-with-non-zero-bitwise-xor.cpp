class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int totalXor = 0;
        bool hasNonZero = false;
        
        for (int num : nums) {
            totalXor ^= num;
            if (num != 0) {
                hasNonZero = true;
            }
        }
        
        // If total XOR is non-zero, take the whole array
        if (totalXor != 0) {
            return nums.size();
        }
        
        // If total XOR is zero, remove one non-zero element if possible
        return hasNonZero ? nums.size() - 1 : 0;
    
    }
};