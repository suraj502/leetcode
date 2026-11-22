class Solution {
public:
    string reverseWords(string s) {
        int n=s.size();
        string ans;
        for(int i=0 ;i<n;i++){
            string curr;
          while( i<n && s[i]!=' '){
            curr+=s[i];
            i++;
          }
          reverse(curr.begin(),curr.end());
        ans += curr;
            if (i < n) {
                ans += ' ';
            }
        
        }
        return ans;
    }
};