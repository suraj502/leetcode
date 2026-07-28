class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();

        // Sort only the first half
        sort(s.begin(), s.begin() + n / 2);

        // Rebuild the second half
        for (int i = 0; i < n / 2; i++) {
            s[n - 1 - i] = s[i];
        }

        return s;
    }
};