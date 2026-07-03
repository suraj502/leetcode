class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
         vector<int>ans;
         for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0)ans.push_back(0);
            else ans.push_back(1);
         }
        map<int,int>mp;
        int sum=0; mp[0]=1;int count=0;
        for (int j=0;j<ans.size();j++){
            sum+=ans[j];
            int target=sum-k;
            if(mp.count(target)){
              count+=mp[target];
            }
            mp[sum]++;
        }

         

return count;
    }
};