class Solution {
public:
    int countCommas(int n) {
        // n<3 retrn 0
        if(n<1000)return 0;
        int ans=0;
        for (int i=1000;i<=n;i++){
            ans++;
        }
return ans;
    }
};