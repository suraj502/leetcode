class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.length(); int balance=0; int j=0;
       for(int i=0; i<n; i++){
    const char c=s[i];
    balance+=(c=='(')-(c==')');
    if ((balance==1 && c=='(')||(balance==0 && c==')')) continue;
    s[j++]=s[i];
} 
return s.substr(0, j); 
    }
};