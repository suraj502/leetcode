class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {

        int n = nums.size();

        vector<pair<int, int>> v;

        for (int i = 0; i < n; i++) {
            v.push_back({nums[i], i});
        }

        sort(v.begin(), v.end());

        vector<int> ans(n);

        int i = 0;

        while (i < n) {

            int j = i;

            // Find group
            while (j + 1 < n &&
                   v[j + 1].first - v[j].first <= limit) {
                j++;
            }

            // Original indices of this group
            vector<int> index;

            for (int k = i; k <= j; k++) {
                index.push_back(v[k].second);
            }

            sort(index.begin(), index.end());

            // Put smallest values at smallest indices
            for (int k = 0; k < index.size(); k++) {
                ans[index[k]] = v[i + k].first;
            }

            i = j + 1;
        }

        return ans;
    }
};