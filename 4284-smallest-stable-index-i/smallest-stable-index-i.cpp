class Solution {
public:
int mini(vector<int>&nums,int start, int end){
    int minel=INT_MAX;
    for(int i=start; i <end; i++){
        minel=min(minel,nums[i]);
    }
    return minel;
}


    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int maxi=-1; int ans=INT_MAX;
        for(int i=0;i<n;i++){
            maxi=max(maxi,nums[i]);
            int minel=mini(nums,i,n);
            int check=maxi-minel;
            if(check<=k){
                ans=min(ans,i);
            }
        }
        if(ans==INT_MAX)return -1;
        return ans;
    }
};