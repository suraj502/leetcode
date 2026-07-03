class Solution {
public:
    int numberOfSubarrays(vector<int>& ans, int k) {
         
         
        map<int,int>mp;
        int sum=0; mp[0]=1;int count=0;
        for (int j=0;j<ans.size();j++){
            sum+=(ans[j]%2);
            int target=sum-k;
            if(mp.count(target)){
              count+=mp[target];
            }
            mp[sum]++;
        }

         

return count;
    }
};