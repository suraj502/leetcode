class Solution {
public:
void generate(vector<string>&ans,int n,string cnt){
 if(cnt.length()==n){
    ans.push_back(cnt);
    return;
 }
    // everytime we can push 1
    generate(ans,n,cnt+'1');
    // push 0
    if(cnt.empty() || cnt.back()!='0'){
        generate(ans,n,cnt+'0');
    }

}
    vector<string> validStrings(int n) {
        vector<string>ans;
        generate(ans,n,"");
        return ans;
    }
};