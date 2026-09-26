class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        string ans;
        int n=s.length();
        unordered_map<string,string>mp;
        for(auto it:knowledge){
            mp[it[0]]=it[1];
        }
        for(int i=0;i<n;i++){
            char ch=s[i];
            if(ch=='('){
                i++;
                string check;
                while(s[i]!=')'){
                   check+=s[i];
                   i++;
                }
                if(mp.find(check)!=mp.end()){
                    ans+=mp[check];
                }
                else{
                    ans+='?';
                }
            }
            else{
            ans+=ch;
            }
        }
        return ans;
    }
};