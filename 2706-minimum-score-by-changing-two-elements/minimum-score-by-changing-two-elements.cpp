class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        int n=nums.size();
        if(n==3)return 0;
        sort(nums.begin(),nums.end());
        int mini=INT_MAX; int check=0;
       // 1 case 
        check=abs(nums[2]-nums[n-1]);
        mini=min(mini,check);
        // 2 case
         check=abs(nums[1]-nums[n-2]);
         mini=min(mini,check);
         // 3 case
         check=abs(nums[0]-nums[n-3]);
         mini=min(mini,check);
         //4
         check=abs(nums[1]-nums[n-2]);
         mini=min(mini,check);
         return mini;
    }
};