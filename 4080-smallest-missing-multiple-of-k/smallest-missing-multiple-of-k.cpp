class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
         int ans=0; int n=nums.size();

         for(int i=k;i<1e9;i+=k){
            bool flag=false;
            for (int j=0;j<n;j++){
              
                if(nums[j]==i){
                    flag=true;
                }
               
            }
            if(!flag)return i;
         }

  return 0;
    }
};