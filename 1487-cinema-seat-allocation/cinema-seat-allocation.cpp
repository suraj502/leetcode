class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        unordered_map<int, vector<int>> mp;

        // Store reserved seats row-wise
        for (auto it : reservedSeats) {
            mp[it[0]].push_back(it[1]);
        }

        int ans = 0;

        // Rows with no reserved seats
        // can accommodate 2 families
        ans += (n - mp.size()) * 2;

        // Process rows having reserved seats
        for (auto &it : mp) {

            vector<int> seats = it.second;

            bool left = true;    // 2,3,4,5
            bool middle = true;  // 4,5,6,7
            bool right = true;   // 6,7,8,9

            for (int seat : seats) {

                if (seat >= 2 && seat <= 5)
                    left = false;

                if (seat >= 4 && seat <= 7)
                    middle = false;

                if (seat >= 6 && seat <= 9)
                    right = false;
            }

            if (left && right) {
                ans += 2;
            }
            else if (left || middle || right) {
                ans += 1;
            }
        }

        return ans;
    }
};