class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.length();
        if(n==0)return 0;
      unordered_map<char,int>mp;
      int l=0; 
      int maxi=-1;
      for(int r=0; r<n;r++){
             mp[s[r]]++;
             while(mp[s[r]]==2){
                mp[s[l]]--;
                l++;
             }
             maxi=max(maxi,r-l+1);
      }  
      return maxi;
    }
};