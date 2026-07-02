class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int>fre(26,0);
        int l=0; int r=0;
        int n=s.length();
        int maxl=0;
        int maxi=0;
        while(r<n){
            fre[s[r]-'A']++;
            maxi=max(maxi,fre[s[r]-'A']);
            while((r-l+1)-maxi>k){
                fre[s[l]-'A']--;
                l++;
            }
            maxl=max(maxl,r-l+1);
            r++;
        }
        return maxl;
    }
};