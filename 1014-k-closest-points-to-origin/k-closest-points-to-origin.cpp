class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // calculate min heap 
       priority_queue<
    tuple<int,int,int>,
    vector<tuple<int,int,int>>,
    greater<tuple<int,int,int>>
> pq;
        for (auto it:points){
            int x=it[0];
            int y=it[1];
           int dist = x*x + y*y;
            pq.push({dist,x,y});

        }
        vector<vector<int>>ans;
       while (k--) {
    auto it = pq.top();

    int b = get<1>(it);
    int c = get<2>(it);

    ans.push_back({b, c});

    pq.pop();
    
}
        return ans;
    }
};