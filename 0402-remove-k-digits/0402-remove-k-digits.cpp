class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char>st;
        int n=num.length();
        for (int i=0;i<n;i++){
            char ch=num[i];
        while(!st.empty() && st.top()>ch&& k>0){
            k--;
            st.pop();
        }
      
        st.push(ch);


}
while(k>0){
    st.pop();
    k--;
}
string s;
while(!st.empty()){
    s+=st.top();
    st.pop();
}

 reverse(s.begin(), s.end());

        // Remove leading zeros
        int i = 0;
        while (i < s.size() && s[i] == '0') {
            i++;
        }

        s = s.substr(i);

        return s.empty() ? "0" : s;





    }
};