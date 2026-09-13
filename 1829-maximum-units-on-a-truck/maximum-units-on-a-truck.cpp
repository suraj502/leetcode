class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int target) {
        int ans=0;
         sort(boxTypes.begin(), boxTypes.end(), [](auto &a, auto &b) {
            return a[1] > b[1];
        });
        for(auto it: boxTypes){
            if(target<=0)break;
            int box=it[0];
            int unit=it[1];
          if(target<=box)box=target;
          
           ans+=box*unit;
           target=target-box;
        }
        return ans;
    }
};