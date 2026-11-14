class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> st;

        for (int r = 0; r < nums.size(); r++) {

            if (st.count(nums[r])) {
                return true;
            }

            st.insert(nums[r]);

            if (st.size() > k) {
                st.erase(nums[r - k]);
            }
        }

        return false;
    }
};