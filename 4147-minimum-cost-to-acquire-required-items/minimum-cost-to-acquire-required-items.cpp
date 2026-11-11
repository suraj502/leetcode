
class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        // edge cases
        if (need1 == 0 && need2 == 0) return 0;

        if (need1 == 0) {
            if (cost2 <= costBoth) {
                return 1LL * cost2 * need2;
            }
            else {
                return 1LL * costBoth * need2;
            }
        }

        if (need2 == 0) {
            if (cost1 <= costBoth) {
                return 1LL * cost1 * need1;
            }
            else {
                return 1LL * costBoth * need1;
            }
        }

        // simple cases
        long long ans = 0;

        if (1LL * cost1 + cost2 < costBoth) {
            ans = 1LL * cost1 * need1 + 1LL * cost2 * need2;
            return ans;
        }
        else {
            if (need1 == need2)
                return 1LL * need1 * costBoth;

            // need1 greater
            if (need1 > need2) {
                ans += 1LL * need2 * costBoth;

                if (cost1 < costBoth) {
                    ans += 1LL * (need1 - need2) * cost1;
                    return ans;
                }
                else {
                    ans += 1LL * (need1 - need2) * costBoth;
                    return ans;
                }
            }

            // need2 greater
            else {
                ans += 1LL * need1 * costBoth;

                if (cost2 < costBoth) {
                    ans += 1LL * (need2 - need1) * cost2;
                    return ans;
                }
                else {
                    ans += 1LL * (need2 - need1) * costBoth;
                    return ans;
                }
            }
        }

        return 0;
    }
};
