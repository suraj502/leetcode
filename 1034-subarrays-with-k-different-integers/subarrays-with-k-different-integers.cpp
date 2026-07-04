class Solution {
public:
int c(vector<int>&arr,int k){
int count =0; int l=0 ; int n=arr.size();
int r=0;
map<int,int>mp;
for(int i=0;i<n;i++){
    mp[arr[i]]++;
    while(mp.size()>k){
   mp[arr[l]]--;
   if(mp[arr[l]]==0){
    mp.erase(arr[l]);
   }
   l++;
    }
    count+=i-l+1;
}
return count;
}

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int ans =c(nums,k)-c(nums,k-1);
        return ans ;
    }
};