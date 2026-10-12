class Solution {
public:
int solve(vector<int>&arr, vector<vector<int>> &dp, int index, int target) {
    int n=arr.size();
    if (target == 0) return 1;
    if (index == n) return 0; // or handle base case properly
    
    if (dp[index][target] != -1) 
        return dp[index][target];
    
    int ans = 0;
    // Using your loop-based approach to explore choices
    for (int i = index; i < n; i++) {
        if (arr[i] <= target) { // changed >= to <= since we subtract from target
            if (solve(arr, dp, i + 1, target - arr[i])) {
                ans = 1;
                break;
            }
        }
    }
    
    return dp[index][target] = ans;
}
    bool canPartition(vector<int>& arr) {
        int n=arr.size(); int sum=0;
        for(int i=0;i<n;i++){
         sum+=arr[i];
        }
        if(sum%2!=0)return false;
        int target=sum/2;
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
       if( solve(arr,dp,0,target)==1)return true;
       return false;
    }
};