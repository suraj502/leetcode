class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int minIndex = 0;
        int maxIndex = 0;

        // Find positions of min and max
        for (int i = 0; i < n; i++) {
            if (nums[i] < nums[minIndex])
                minIndex = i;

            if (nums[i] > nums[maxIndex])
                maxIndex = i;
        }

        // a = leftmost index
        // b = rightmost index
        int a = min(minIndex, maxIndex);
        int b = max(minIndex, maxIndex);

        // 1. Remove both from the LEFT
        int left = b + 1;

        // 2. Remove both from the RIGHT
        int right = n - a;

        // 3. Remove one from LEFT and one from RIGHT
        int both = (a + 1) + (n - b);

        return min({left, right, both});
    }
};