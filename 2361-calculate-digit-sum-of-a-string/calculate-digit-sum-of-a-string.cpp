class Solution {
public:
    string digitSum(string s, int k) {
        int n = s.size();

        while (s.length() > k) {
            string curr = "";

            for (int i = 0; i < n;) {
                int check = k;
                int sum = 0;

                while (check > 0 && i < n) {
                    int num = s[i] - '0';
                    sum += num;
                    i++;
                    check--;
                }

                curr += to_string(sum);
            }

            s = curr;
            n = s.size();
        }

        return s;
    }
};