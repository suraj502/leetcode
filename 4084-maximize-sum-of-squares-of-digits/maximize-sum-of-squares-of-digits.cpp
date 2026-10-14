class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
         string ans;
        while (num > 0) {
            int dig = min(9, sum);
            ans += char('0' + dig);
            sum -= dig;
            num--;
        }
        if (sum > 0) return "";  // not possible to make this sum
        return ans;
    }
};