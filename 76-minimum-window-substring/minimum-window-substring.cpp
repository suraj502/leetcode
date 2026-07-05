class Solution {
public:
    string minWindow(string s, string t) {
     vector<int>hash(256,0);
     for(int i=0;i<t.length();i++){
        hash[t[i]]++;
     }
     int right=0; int n=s.length();
     int mini=INT_MAX; int cnt=0;
     int start = -1;int l=0;
     while(right<n){
   if(hash[s[right]]>0){
    cnt++;
  
   }
    hash[s[right]]--;
  while(cnt==t.length()){
    if(right-l+1<mini){
        mini=right-l+1;
        start=l;
    }
    hash[s[l]]++;
    if(hash[s[l]]>0)cnt--;
    l++;
  }
right++;
  }

return start==-1?"":s.substr(start,mini);


    }
};