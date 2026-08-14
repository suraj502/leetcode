class Solution {
public:
    int maximumLengthSubstring(string s) {
        int maxi=0;
        unordered_map<char,int>mp;
        int l=0;
        for(int r=0;r<s.length();r++){
            mp[s[r]]++;
            while(mp[s[r]]>2){
                mp[s[l]]--;
                if(mp[s[l]]==0)mp.erase(s[l]);
                l++;
            }
            maxi=max(maxi,r-l+1);
        }
        return maxi;
    }
};