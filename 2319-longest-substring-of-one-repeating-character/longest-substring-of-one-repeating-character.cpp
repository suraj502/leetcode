class Solution {
public:

    struct Node {
        char leftChar;
        char rightChar;
        int prefix;
        int suffix;
        int best;

        Node() {
            leftChar = '#';
            rightChar = '#';
            prefix = suffix = best = 0;
        }
    };

    vector<Node> seg;
    string s;

    Node merge(Node a, Node b) {

        if (a.best == 0) return b;
        if (b.best == 0) return a;

        Node res;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        // Best answer can simply be from either side
        res.best = max(a.best, b.best);

        // If boundary characters are same,
        // suffix of left + prefix of right can join
        if (a.rightChar == b.leftChar) {

            res.best = max(res.best, a.suffix + b.prefix);

            // Entire left segment has same character
            if (a.prefix == length(a)) {
                res.prefix = a.prefix + b.prefix;
            } else {
                res.prefix = a.prefix;
            }

            // Entire right segment has same character
            if (b.suffix == length(b)) {
                res.suffix = a.suffix + b.suffix;
            } else {
                res.suffix = b.suffix;
            }

        } else {
            res.prefix = a.prefix;
            res.suffix = b.suffix;
        }

        return res;
    }

    int length(Node x) {
        // We cannot determine segment length from Node,
        // so this approach needs segment lengths.
        return 0;
    }

    void build(int idx, int l, int r) {

        if (l == r) {
            seg[idx].leftChar = s[l];
            seg[idx].rightChar = s[l];
            seg[idx].prefix = 1;
            seg[idx].suffix = 1;
            seg[idx].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        build(2 * idx, l, mid);
        build(2 * idx + 1, mid + 1, r);

        seg[idx] = merge(seg[2 * idx], seg[2 * idx + 1], l, r);
    }

    Node merge(Node a, Node b, int l, int r) {

        if (a.best == 0) return b;
        if (b.best == 0) return a;

        Node res;

        res.leftChar = a.leftChar;
        res.rightChar = b.rightChar;

        res.prefix = a.prefix;
        res.suffix = b.suffix;

        res.best = max(a.best, b.best);

        if (a.rightChar == b.leftChar) {

            res.best = max(res.best, a.suffix + b.prefix);

            int mid = (l + r) / 2;

            int leftLength = mid - l + 1;
            int rightLength = r - mid;

            if (a.prefix == leftLength)
                res.prefix = leftLength + b.prefix;

            if (b.suffix == rightLength)
                res.suffix = a.suffix + rightLength;
        }

        return res;
    }

    void update(int idx, int l, int r, int pos, char c) {

        if (l == r) {
            seg[idx].leftChar = c;
            seg[idx].rightChar = c;
            seg[idx].prefix = 1;
            seg[idx].suffix = 1;
            seg[idx].best = 1;
            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid)
            update(2 * idx, l, mid, pos, c);
        else
            update(2 * idx + 1, mid + 1, r, pos, c);

        seg[idx] = merge(
            seg[2 * idx],
            seg[2 * idx + 1],
            l,
            r
        );
    }

    vector<int> longestRepeating(
        string s,
        string queryCharacters,
        vector<int>& queryIndices
    ) {

        this->s = s;

        int n = s.size();

        seg.resize(4 * n);

        build(1, 0, n - 1);

        vector<int> ans;

        for (int i = 0; i < queryIndices.size(); i++) {

            int pos = queryIndices[i];
            char c = queryCharacters[i];

            s[pos] = c;

            update(1, 0, n - 1, pos, c);

            ans.push_back(seg[1].best);
        }

        return ans;
    }
};