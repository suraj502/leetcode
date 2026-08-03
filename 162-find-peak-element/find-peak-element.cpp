class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n=nums.size()-1;
        int low=1; int high=n-1;
        if (nums.size() == 1) return 0;
        if(nums[1]<nums[0])return 0;
        if(nums[n]>nums[n-1])return n;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]>nums[mid-1]&& nums[mid]>nums[mid+1])return mid;
            if(nums[mid-1]<nums[mid]){
                low=mid+1;
            }
            else{
                high=mid-1;
            }
        }
 return -1;

    }
};