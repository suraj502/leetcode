class Solution {
public:
bool possible(int mid,int k,vector<int>&nums){
    int count=1;
    int value=0;
    for(int i:nums){
if(value+i<=mid){
value+=i;
}
else{
count++;
value=i;
}

    }
    if(count<=k)return true;
    return false;
}
    int splitArray(vector<int>& nums, int k) {
         int low = *max_element(nums.begin(), nums.end());
         int high= accumulate(nums.begin(), nums.end(), 0);
       
         while(low<=high){
            int mid=(low+high)/2;
            if(possible(mid,k,nums)){
               
                high=mid-1;
            }
            else{
                low=mid+1;
            }
         }
return low;
    }
};