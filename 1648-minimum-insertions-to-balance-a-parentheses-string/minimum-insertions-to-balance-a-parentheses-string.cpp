class Solution {
public:
    int minInsertions(string s) {

        stack<char> st;
        int ans = 0;

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '(') {
                st.push('(');
            }
            else {

                // Check whether we have ))
                if (i + 1 < s.size() && s[i + 1] == ')') {
                    i++;  // consume second ')'
                }
                else {
                    // Only one ')' -> insert another ')'
                    ans++;
                }

                // Now we have a complete ))
                if (!st.empty()) {
                    st.pop();
                }
                else {
                    // No '(' to match this ))
                    ans++; // insert '('
                }
            }
        }

        // Remaining '(' each need ))
        ans += st.size() * 2;

        return ans;
    }
};