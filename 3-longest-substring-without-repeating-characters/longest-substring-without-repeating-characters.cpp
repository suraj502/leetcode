class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int hash[256] = {0};

        int left = 0;
        int ans = 0;

        for(int right = 0; right < s.size(); right++) {

            hash[s[right]]++;

            while(hash[s[right]] > 1) {
                hash[s[left]]--;
                left++;
            }

            ans = max(ans, right - left + 1);
        }

        return ans;
    }
};