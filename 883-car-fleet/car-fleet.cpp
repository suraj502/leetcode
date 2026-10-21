
class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int, double>> cal;
       

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
        int fleet=0;    double max_time = 0.0;
        for (int i = n - 1; i >= 0; i--) {
            if ( cal[i].second >max_time) {
                fleet++;
                 max_time =cal[i].second;
            }
        }

        return fleet;
    }
};
