class Solution {
public:
    int search(vector<int>& nums, int target) {
      int n=nums.size();
      int low=0; int high=n-1;
      while(low<=high){
  int mid=(low+high)/2;
  if(nums[mid]==target)return mid;
       // if left half is sorted or not 
       if(nums[low]<=nums[mid]){
     // check if target is present or not 
     if(target>=nums[low] && target<nums[mid]){
     high=mid-1;
     }
     else{
low=mid+1;
     }
       }
       // right half is sorted 
       else{
          if(target>nums[mid]&& target<=nums[high]){
            low=mid+1;
          }
          else{
            high=mid-1;
          }
       }
      } 
      return -1;   
    }
};