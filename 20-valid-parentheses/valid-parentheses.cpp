class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for (int ch=0;ch<s.length();ch++){
            if(s[ch]=='('|| s[ch]=='{'|| s[ch]=='['){
                st.push(s[ch]);
            }
            else{
                if(st.empty())return false;
                char c=st.top(); st.pop();
                if(s[ch]==')'&& c!='(' || s[ch]=='}'&& c!='{' || s[ch]==']'&& c!='['  ) return false;
            }
        }
        return st.empty();
    }
};