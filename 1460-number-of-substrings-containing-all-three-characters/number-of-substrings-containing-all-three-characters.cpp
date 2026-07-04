class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int>ans(3,0);
        int l=0; int n=s.length();
        int res=0;
        for(int right=0; right<n;right++){
            ans[s[right]-'a']++;
            while(ans[0]>0 && ans[1]>0 && ans[2]>0){
           res+=n-right;
         ans[s[l]-'a']--;
         l++;
            }
        }

return res;

    }
};