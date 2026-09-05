class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();

        vector<int>prefix(n);
        vector<int> suffix(n); int maxi=-1; int mini=INT_MAX;
        for(int i=0;i<n;i++){
           maxi=max(maxi,nums[i]);
           mini=min(mini,nums[n-1-i]);
           prefix[i]=maxi;
           suffix[n-1-i]=mini;
        }
        int ans=INT_MAX;
        for(int i=0;i<n;i++){
           int maximum=prefix[i];
           int minimum=suffix[i];
           int check=maximum-minimum;
           if(check<=k){
           ans=min(ans,i);
           } 
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};