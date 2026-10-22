class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
         int n=nums.size();
         vector<int>dp(n,1);
         sort(nums.begin(),nums.end());
         vector<int>parent(n);
         for(int i=0;i<n;i++){
            parent[i]=i;
         }
         int maxi=0;
         int lastIndex=0;
         for(int i=0;i<n;i++){
            for(int prev=0;prev<i; prev++){
                if(nums[i]%nums[prev]==0 && dp[prev]+1 >dp[i] ){
                    dp[i]=dp[prev]+1;
                    parent[i]=prev;
                }
            }
            if(dp[i]>maxi){
                maxi=dp[i];
                lastIndex=i;
            }
         }
         vector<int>ans;
         while(parent[lastIndex]!=lastIndex){
            ans.push_back(nums[lastIndex]);
            lastIndex=parent[lastIndex];
         }
              ans.push_back(nums[lastIndex]);
        reverse(ans.begin(), ans.end());

        return ans;

    }
};