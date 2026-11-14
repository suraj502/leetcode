class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n = s.size();
        unordered_set<string> an;
        unordered_set<string> st;

        string curr;

        for (int r = 0; r < n; r++) {
            curr += s[r];

            if (curr.size() == 10) {
                if (st.count(curr)) {
                    an.insert(curr);
                }
                else {
                    st.insert(curr);
                }

                curr.erase(curr.begin());
            }
        }

        vector<string> ok(an.begin(), an.end());

        return ok;
    }
};