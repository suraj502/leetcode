class Solution {
public:

    struct Node {
        int prod;
        int cnt[5];

        Node() {
            prod = 1;
            for (int i = 0; i < 5; i++)
                cnt[i] = 0;
        }
    };

    int n, k;
    vector<Node> seg;

    Node mergeNode(const Node& a, const Node& b) {

        Node res;

        // Product of the complete segment
        res.prod = (a.prod * b.prod) % k;

        // Prefixes completely inside left segment
        for (int r = 0; r < k; r++) {
            res.cnt[r] += a.cnt[r];
        }

        // Prefixes which start in left and continue into right
        for (int r = 0; r < k; r++) {

            int newRem = (a.prod * r) % k;

            res.cnt[newRem] += b.cnt[r];
        }

        return res;
    }

    void build(int node, int l, int r, vector<int>& nums) {

        if (l == r) {

            int rem = nums[l] % k;

            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        build(node * 2, l, mid, nums);
        build(node * 2 + 1, mid + 1, r, nums);

        seg[node] = mergeNode(
            seg[node * 2],
            seg[node * 2 + 1]
        );
    }

    void update(
        int node,
        int l,
        int r,
        int pos,
        int value
    ) {

        if (l == r) {

            int rem = value % k;

            seg[node] = Node();

            seg[node].prod = rem;
            seg[node].cnt[rem] = 1;

            return;
        }

        int mid = (l + r) / 2;

        if (pos <= mid) {
            update(node * 2, l, mid, pos, value);
        }
        else {
            update(node * 2 + 1, mid + 1, r, pos, value);
        }

        seg[node] = mergeNode(
            seg[node * 2],
            seg[node * 2 + 1]
        );
    }

    Node query(
        int node,
        int l,
        int r,
        int ql,
        int qr
    ) {

        // Completely inside
        if (ql <= l && r <= qr) {
            return seg[node];
        }

        int mid = (l + r) / 2;

        // Completely in left
        if (qr <= mid) {
            return query(
                node * 2,
                l,
                mid,
                ql,
                qr
            );
        }

        // Completely in right
        if (ql > mid) {
            return query(
                node * 2 + 1,
                mid + 1,
                r,
                ql,
                qr
            );
        }

        // Overlap
        Node left = query(
            node * 2,
            l,
            mid,
            ql,
            qr
        );

        Node right = query(
            node * 2 + 1,
            mid + 1,
            r,
            ql,
            qr
        );

        return mergeNode(left, right);
    }

    vector<int> resultArray(
        vector<int>& nums,
        int K,
        vector<vector<int>>& queries
    ) {

        n = nums.size();
        k = K;

        seg.resize(4 * n);

        build(1, 0, n - 1, nums);

        vector<int> ans;
        ans.reserve(queries.size());

        for (auto& q : queries) {

            int index = q[0];
            int value = q[1];
            int start = q[2];
            int x = q[3];

            // Persistent update
            update(
                1,
                0,
                n - 1,
                index,
                value
            );

            // Query [start ... n-1]
            Node res = query(
                1,
                0,
                n - 1,
                start,
                n - 1
            );

            ans.push_back(res.cnt[x]);
        }

        return ans;
    }
};