class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++){
            int a =target-nums[i];
            if(mp.count(a)){
               ans.push_back(mp[a]);
               ans.push_back(i);
               break;
            }
            mp[nums[i]]=i;
        }
       return ans;
    }
};