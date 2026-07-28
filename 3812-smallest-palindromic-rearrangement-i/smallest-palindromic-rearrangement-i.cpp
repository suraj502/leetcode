class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size() / 2;

sort(s.begin(), s.begin() + n);

if (s.size() % 2 == 0)
    sort(s.begin() + n, s.end(), greater<char>());
else
    sort(s.begin() + n + 1, s.end(), greater<char>());
    return s;
    }
};