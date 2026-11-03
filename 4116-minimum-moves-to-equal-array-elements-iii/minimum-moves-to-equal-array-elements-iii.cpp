class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        for(auto it:nums){
            ans+=nums[n-1]-it;
        }
        return ans;
    }
};