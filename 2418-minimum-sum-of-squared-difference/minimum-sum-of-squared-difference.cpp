
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,
                               int k1, int k2) {
        long long k = 1LL * k1 + k2;
        vector<long long> diff;
        long long mx = 0, total = 0;

        for (int i = 0; i < nums1.size(); i++) {
            long long d = abs(nums1[i] - nums2[i]);
            diff.push_back(d);
            mx = max(mx, d);
            total += d;
        }

        if (total <= k) return 0;

        long long low = 0, high = mx;

        while (low < high) {
            long long mid = low + (high - low) / 2;
            long long need = 0;

            for (long long d : diff) {
                if (d > mid) need += d - mid;
            }

            if (need <= k) high = mid;
            else low = mid + 1;
        }

        long long limit = low;
        long long used = 0, ans = 0;

        for (long long& d : diff) {
            if (d > limit) {
                used += d - limit;
                d = limit;
            }
        }

        long long remaining = k - used;

        for (long long& d : diff) {
            if (remaining == 0) break;

            if (d == limit && d > 0) {
                d--;
                remaining--;
            }
        }

        for (long long d : diff) {
            ans += d * d;
        }

        return ans;
    }
};
