class Solution {
public:
    bool canCross(vector<int>& stones) {
        int n = stones.size();

        if (stones[1] != 1)
            return false;

        unordered_map<int, unordered_set<int>> visited;

        queue<pair<int, int>> q;

        // {stone index, previous jump}
        q.push({1, 1});
        visited[1].insert(1);

        while (!q.empty()) {
            auto [i, jump] = q.front();
            q.pop();

            if (i == n - 1)
                return true;

            for (int nextJump = jump - 1;
                 nextJump <= jump + 1;
                 nextJump++) {

                if (nextJump <= 0)
                    continue;

                int nextPos = stones[i] + nextJump;

                auto it = lower_bound(stones.begin() + i + 1,
                                      stones.end(),
                                      nextPos);

                if (it != stones.end() && *it == nextPos) {
                    int nextIndex = it - stones.begin();

                    if (!visited[nextIndex].count(nextJump)) {
                        visited[nextIndex].insert(nextJump);
                        q.push({nextIndex, nextJump});
                    }
                }
            }
        }

        return false;
    }
};