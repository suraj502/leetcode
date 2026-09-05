class Solution {
public:
  void helper(vector<int>&candidates,int index,int n,int target ,vector<vector<int>>&ans,vector<int>curr){
    // base case 
    
        if(target==0){
            ans.push_back(curr);
         return ;}
    
   
    // loop to take the el backtarck 
    for(int i=index;i<n;i++){
      if(i>index && candidates[i]==candidates[i-1])continue;
        if(candidates[i]>target)break;
        curr.push_back(candidates[i]);
        helper(candidates,i+1,n,target-candidates[i],ans,curr);
        curr.pop_back();
    }
  }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>curr;
        int n=candidates.size();
        helper(candidates,0,n,target,ans,curr);
        return ans;
    }
};