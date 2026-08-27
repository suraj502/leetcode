class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();

        vector<int> freq(26, 0);

        for (char c : s) {
            freq[c - 'a']++;
        }

        // Match target from left to right as much as possible
        int i = 0;

        while (i < n && freq[target[i] - 'a'] > 0) {
            freq[target[i] - 'a']--;
            i++;
        }

        // Case 1:
        // We could not match target[i].
        // Try making this position greater.
        if (i < n) {
            for (int c = target[i] - 'a' + 1; c < 26; c++) {

                if (freq[c] > 0) {
                    string ans = target.substr(0, i);

                    ans += char('a' + c);
                    freq[c]--;

                    // Smallest possible suffix
                    for (int j = 0; j < 26; j++) {
                        while (freq[j] > 0) {
                            ans += char('a' + j);
                            freq[j]--;
                        }
                    }

                    return ans;
                }
            }
        }

        // Case 2:
        // We need to backtrack.
        //
        // We matched target[0 ... i-1].
        // Try changing one of those positions to something bigger.

        for (int j = i - 1; j >= 0; j--) {

            // Restore target[j] because we are changing this position
            freq[target[j] - 'a']++;

            // Find the smallest character greater than target[j]
            for (int c = target[j] - 'a' + 1; c < 26; c++) {

                if (freq[c] > 0) {
                    string ans = target.substr(0, j);

                    ans += char('a' + c);
                    freq[c]--;

                    // Fill remaining characters in smallest order
                    for (int k = 0; k < 26; k++) {
                        while (freq[k] > 0) {
                            ans += char('a' + k);
                            freq[k]--;
                        }
                    }

                    return ans;
                }
            }
        }

        return "";
    }
};