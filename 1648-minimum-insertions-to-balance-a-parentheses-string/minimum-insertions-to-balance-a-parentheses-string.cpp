class Solution {
public:
    int minInsertions(string s) {
        int ans = 0;
        int cnt = 0;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (cnt % 2 == 1) {
                    ans++;
                    cnt--;
                }
                cnt += 2;
            } 
            else {
                cnt--;

                if (cnt < 0) {
                    ans++;
                    cnt = 1;
                }
            }
        }

        return ans + cnt;
    }
};