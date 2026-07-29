class Solution {
public:
    using ll = long long;
    static constexpr ll LIM = 1000000LL;

    ll C(int n, int r) {
        if (r < 0 || r > n) return 0;
        r = min(r, n - r);

        ll ans = 1;

        for (int i = 1; i <= r; i++) {
            ll a = n - r + i;
            ll b = i;

            ll g = gcd(a, b);
            a /= g;
            b /= g;

            g = gcd(ans, b);
            ans /= g;
            b /= g;

            if (ans > LIM / a) return LIM;
            ans *= a;
            ans /= b;

            if (ans > LIM) ans = LIM;
        }

        return min(ans, LIM);
    }

    ll countWays(vector<int>& cnt) {
        int rem = 0;
        for (int x : cnt) rem += x;

        ll ways = 1;

        for (int x : cnt) {
            if (x == 0) continue;

            ll choose = C(rem, x);

            if (ways > LIM / choose)
                ways = LIM;
            else
                ways *= choose;

            if (ways > LIM) ways = LIM;

            rem -= x;
        }

        return ways;
    }

    string smallestPalindrome(string s, int k) {

        vector<int> freq(26);

        for (char c : s)
            freq[c - 'a']++;

        vector<int> half(26);
        string mid = "";

        for (int i = 0; i < 26; i++) {
            half[i] = freq[i] / 2;
            if (freq[i] & 1)
                mid.push_back(char('a' + i));
        }

        if (countWays(half) < k)
            return "";

        int len = s.size() / 2;
        string first;

        for (int pos = 0; pos < len; pos++) {

            for (int c = 0; c < 26; c++) {

                if (half[c] == 0) continue;

                half[c]--;

                ll ways = countWays(half);

                if (ways >= k) {
                    first.push_back(char('a' + c));
                    break;
                }

                k -= ways;
                half[c]++;
            }
        }

        string second = first;
        reverse(second.begin(), second.end());

        return first + mid + second;
    }
};