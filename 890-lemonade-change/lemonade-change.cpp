class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int f = 0;
        int t = 0;

        for (int bill : bills) {

            if (bill == 5) {
                f++;
            }

            else if (bill == 10) {
                if (f == 0)
                    return false;

                f--;
                t++;
            }

            else { // bill == 20

                // Prefer 10 + 5
                if (t > 0 && f > 0) {
                    t--;
                    f--;
                }

                // Otherwise use 5 + 5 + 5
                else if (f >= 3) {
                    f -= 3;
                }

                else {
                    return false;
                }
            }
        }

        return true;
    }
};