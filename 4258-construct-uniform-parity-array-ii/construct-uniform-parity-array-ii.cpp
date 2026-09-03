class Solution {
public:
int smallestodd(vector<int>&nums1, int n){
   int mini=INT_MAX;
    for(int i=0;i<n;i++){
   if(nums1[i]%2!=0){
   mini=min(mini,nums1[i]);
   }
    }
    return mini;
}
int smallesteven(vector<int>&nums1, int n){
   int mini=INT_MAX;
    for(int i=0;i<n;i++){
   if(nums1[i]%2==0){
  mini=min(mini,nums1[i]); 
   }
    }
    return mini;
}
    bool uniformArray(vector<int>& nums1) {
       int n=nums1.size();
       if(n==1)return true;
   int odd=smallestodd(nums1,n);
  int  even=smallesteven(nums1,n);
  if(odd==INT_MAX || even==INT_MAX)return true;
    if(odd<even)return true;
    return false;
    }
};