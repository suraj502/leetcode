class Solution {
public:
    int numDifferentIntegers(string word) {
        int n = word.size();
        unordered_set<string> st;

        for (int i = 0; i < n; i++) {

            if (isdigit(word[i])) {

                string digit = "";

                while (i < n && isdigit(word[i])) {
                    digit += word[i];
                    i++;
                }

                // Remove leading zeros
                int j = 0;
                while (j < digit.size() && digit[j] == '0') {
                    j++;
                }

                digit = digit.substr(j);

                if (digit.empty()) {
                    digit = "0";
                }

                st.insert(digit);
            }
        }

        return st.size();
    }
};