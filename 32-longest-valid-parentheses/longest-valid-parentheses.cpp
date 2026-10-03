class Solution {
public:
    int longestValidParentheses(string s) {

        stack<int> st;

        // Starting point
        st.push(-1);

        int maxi = 0;

        for (int i = 0; i < s.length(); i++) {

            // If opening bracket
            if (s[i] == '(') {

                st.push(i);
            }

            // If closing bracket
            else {

                // Remove the matching '('
                st.pop();

                // If stack becomes empty
                if (st.empty()) {

                    // Current position becomes new starting point
                    st.push(i);
                }

                // Otherwise calculate valid length
                else {

                    int length = i - st.top();

                    if (length > maxi) {
                        maxi = length;
                    }
                }
            }
        }

        return maxi;
    }
};