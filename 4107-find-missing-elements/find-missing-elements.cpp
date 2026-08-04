class Solution {
public:
    vector<int> findMissingElements(vector<int>& v) {
        int mx = *max_element(v.begin(), v.end());
        int mn = *min_element(v.begin(), v.end());
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<v.size();i++){
            mp[v[i]]=1;
        }
        for(int i=mn;i<=mx;i++){
            if(mp.find(i)==mp.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};