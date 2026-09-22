class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int  n=nums.size();
        unordered_map<int,int>mp;
        for (int i=0;i<n;i++){
             mp[nums[i]]++;
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto it :mp){
            int freq=it.second;
            int num=it.first;
          pq.push({freq,num});
          while(pq.size()>k){
            pq.pop();
          }
        }
        vector<int>ans;
        while(!pq.empty()){
            auto it=pq.top();
            int no=it.second;
            ans.push_back(no);
            pq.pop();
        }
        return ans;
    }
};