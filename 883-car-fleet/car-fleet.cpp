
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cal;
        stack<pair<int, double>> st;

        int n = position.size();

        // Calculate arrival time
        for (int i = 0; i < n; i++) {
            double dst = target - position[i];
            double time = dst / speed[i];
            cal.push_back({position[i], time});
        }

        // Sort by position
        sort(cal.begin(), cal.end());

        // Process from closest to target to farthest
        for (int i = n - 1; i >= 0; i--) {
            if (st.empty() || cal[i].second > st.top().second) {
                st.push(cal[i]);
            }
        }

        return st.size();
    }
};
