class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& curr) {
        int mini=INT_MAX;
        sort(curr.begin(),curr.end());
         for(int i=0; i<curr.size()-1;i++){
       int no=abs(curr[i]-curr[i+1]);
       mini=min(mini,no);
      }
      vector<vector<int>>ans;
        for(int i=0 ;i<curr.size()-1;i++){
             int no=abs(curr[i]-curr[i+1]);
             if(no==mini){
                ans.push_back({curr[i],curr[i+1]});
             }
        }
        return ans;
    }
};