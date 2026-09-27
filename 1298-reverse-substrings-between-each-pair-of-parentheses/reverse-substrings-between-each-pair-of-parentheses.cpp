class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st;

        for (char ch : s) {

            // Opening bracket
            if (ch == '(') {
                st.push(ch);
            }

            // Closing bracket
            else if (ch == ')') {

                string temp;

                // Pop until we find the matching '('
                while (st.top() != '(') {
                    temp += st.top();
                    st.pop();
                }

                // Remove '('
                st.pop();

                // Put the reversed substring back into stack
                for (char c : temp) {
                    st.push(c);
                }
            }

            // Normal character
            else {
                st.push(ch);
            }
        }

        // Build final answer
        string ans;

        while (!st.empty()) {
            ans += st.top();
            st.pop();
        }

        // Stack gives characters backwards
        reverse(ans.begin(), ans.end());

        return ans;
    }
};