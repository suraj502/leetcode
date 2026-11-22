class Solution {
public:
    string reverseStr(string s, int k) {
        int n=s.length();
        string ans; int l=k; int r=0; string curr;
        for(int i=0 ;i<n;i++){
             //add k el
             while(i<n && l>0){
                curr+=s[i];
                l--;
                r++;
                i++;
             }
             reverse(curr.begin(),curr.end());
             ans+=curr;
             curr="";
             while(i<n && r>0){
                ans+=s[i];
                r--;
                l++;
                i++;
             }

  i--;

        }
        return ans;
    }
};