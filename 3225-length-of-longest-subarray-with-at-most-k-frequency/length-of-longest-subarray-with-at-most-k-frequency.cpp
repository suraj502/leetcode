class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int length=INT_MIN;
        unordered_map<int,int>mp;
        int l=0;
        for(int r=0;r<nums.size();r++){
            mp[nums[r]]++;
            while(mp[nums[r]]>k){
                mp[nums[l]]--;
                if(mp[nums[l]]==0)mp.erase(nums[l]);
                l++;
            }
            length=max(length,r-l+1);
        }
        return length;
    }
};