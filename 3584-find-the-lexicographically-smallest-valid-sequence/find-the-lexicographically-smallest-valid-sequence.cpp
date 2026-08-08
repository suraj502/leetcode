class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        // suf[i] = maximum number of characters from
        // word2[j...] that can be matched using word1[i...]
        vector<int> suf(n + 1, 0);

        int j = m - 1;

        for (int i = n - 1; i >= 0; i--) {
            suf[i] = suf[i + 1];

            if (j >= 0 && word1[i] == word2[j]) {
                suf[i]++;
                j--;
            }
        }

        vector<int> ans;

        int pos = 0;
        bool usedMismatch = false;

        for (int i = 0; i < n && pos < m; i++) {

            // Exact match: always take it
            if (word1[i] == word2[pos]) {
                ans.push_back(i);
                pos++;
            }

            // Mismatch: use our one allowed change
            else if (!usedMismatch) {

                // After taking i as the mismatch,
                // we need to match word2[pos+1 ...]
                int remaining = m - pos - 1;

                if (suf[i + 1] >= remaining) {
                    ans.push_back(i);
                    pos++;
                    usedMismatch = true;
                }
            }
        }

        if (pos == m)
            return ans;

        return {};
    }
};