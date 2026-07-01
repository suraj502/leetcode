class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int>mp; int maxi=0;
        int left=0; int right=0;
        while(right<s.length()){
           
                mp[s[right]]++;
                
            while(mp[s[right]]>1){
                mp[s[left]]--;
                if(mp[s[left]]==0){
                    mp.erase(s[left]);
                    
                }
              
                  left++;
            }

maxi=max(maxi,right-left+1);
right++;

        }
        return maxi;
    }
};