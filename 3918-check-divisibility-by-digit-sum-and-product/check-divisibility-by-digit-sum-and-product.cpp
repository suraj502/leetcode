class Solution {
public:
    bool checkDivisibility(int n) {
        int sum =0; int pro=1;
        int num=n;
        while(num){
            int rem=num%10;
            sum+=rem;
            pro*=rem;
            num=num/10;
        }
        if(n%(sum+pro)==0){
            return true;
        }
        return false;
    }
};