class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int ,int>mp;
        for(auto it :nums){
            if(mp[it]==0){
                mp[it]=1;
            }
        }
         int i=0;
         for(auto it:mp){
            int num=it.first;
            nums[i]=num;
            i++;
         }
        return mp.size();
    }
};