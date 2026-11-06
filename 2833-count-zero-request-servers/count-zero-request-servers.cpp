class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {

        sort(logs.begin(), logs.end(), [](auto &a, auto &b) {
            return a[1] < b[1];
        });

        int m = queries.size();

        vector<pair<int,int>> q;
        for(int i = 0; i < m; i++) {
            q.push_back({queries[i], i});
        }

        sort(q.begin(), q.end());

        unordered_map<int,int> mp;
        vector<int> ans(m);

        int left = 0, right = 0;
        int inactive = n;

        for(auto &it : q) {

            int start = it.first - x;
            int end = it.first;

            while(right < logs.size() && logs[right][1] <= end) {

                int id = logs[right][0];

                mp[id]++;

                if(mp[id] == 1) {
                    inactive--;
                }

                right++;
            }

            while(left < right && logs[left][1] < start) {

                int id = logs[left][0];

                mp[id]--;

                if(mp[id] == 0) {
                    inactive++;
                }

                left++;
            }

            ans[it.second] = inactive;
        }

        return ans;
    }
};