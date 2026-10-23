
class Solution {
public:
    bool check(string a, string b) {
        if (a.size() + 1 != b.size())
            return false;

        int i = 0, j = 0;

        while (i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i++;
            }
            j++;
        }

        return i == a.size();
    }

    int longestStrChain(vector<string>& words) {
        int n = words.size();

        sort(words.begin(), words.end(),
             [](string& a, string& b) {
                 return a.size() < b.size();
             });

        vector<int> dp(n, 1);
        int maxi = 1;

        for (int i = 0; i < n; i++) {
            for (int prev = 0; prev < i; prev++) {
                if (check(words[prev], words[i])) {
                    dp[i] = max(dp[i], 1 + dp[prev]);
                }
            }

            maxi = max(maxi, dp[i]);
        }

        return maxi;
    }
};
