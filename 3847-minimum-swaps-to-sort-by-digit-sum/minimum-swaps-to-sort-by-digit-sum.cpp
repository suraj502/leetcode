class Solution {
public:
    void make(vector<int>& nums,
              vector<tuple<int, int, int>>& temp, int n) {
        for (int i = 0; i < n; i++) {
            int check = nums[i];
            int sum = 0;

            while (check != 0) {
                sum += check % 10;
                check /= 10;
            }

            temp.push_back({sum, nums[i], i});
        }
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        vector<tuple<int, int, int>> temp;
        make(nums, temp, n);
        sort(temp.begin(), temp.end());

        vector<int> target(n);

        for (int i = 0; i < n; i++) {
            target[get<2>(temp[i])] = i;
        }

        int swaps = 0;

        for (int i = 0; i < n; i++) {
            while (target[i] != i) {
                int j = target[i];
                swap(target[i], target[j]);
                swaps++;
            }
        }

        return swaps;
    }
};