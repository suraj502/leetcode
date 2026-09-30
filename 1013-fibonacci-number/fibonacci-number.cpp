class Solution {
public:
    int fib(int n) {
        if(n<=1)return n;
        int prev2=0; int prev=1;
        int ans=0;
        for(int i=2;i<=n;i++){
           ans=prev+prev2;
            prev2=prev;
           prev=ans;
          
        }
        return ans;
    }
};