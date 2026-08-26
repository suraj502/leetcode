class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        int l = 0, count = 0;
        int len = INT_MAX;
        int start = 0;

        for (int r = 0; r < n; r++) {

            if (s[r] == '1')
                count++;

            while (count == k && s[l] == '0') {
                l++;
            }

            if (count == k) {
                int currLen = r - l + 1;

                if (currLen < len ||
                    (currLen == len && s.substr(l, currLen) < s.substr(start, len))) {
                    len = currLen;
                    start = l;
                }

                // Remove the leftmost 1
                if (s[l] == '1') {
                    count--;
                    l++;
                }
            }
        }

        if (len == INT_MAX)
            return "";

        return s.substr(start, len);
    }
};