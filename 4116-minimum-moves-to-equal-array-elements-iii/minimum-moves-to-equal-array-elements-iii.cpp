class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int max=INT_MIN;
       for(int i = 0; i < nums.size(); ++i) {
            if(max < nums[i]) max = nums[i];
        }

        int ans=0;
        for(auto it:nums){
            ans+=max-it;
        }
        return ans;
    }
};