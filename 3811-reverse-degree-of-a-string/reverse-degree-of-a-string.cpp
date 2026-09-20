class Solution {
public:
    int reverseDegree(string s) {
        char c='a'; int sum=0; int pro=1;
        for(int i=0;i<s.length();i++){
            char ch=s[i];
            int x=ch-'a';
            x=26-x;
            pro=x*(i+1);
            sum+=pro;
        }
        return sum;
    }
};