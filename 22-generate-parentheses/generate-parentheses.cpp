class Solution {
public:
  void solve(int n ,vector<string>&ans,int open, int close,int index,string curr){
     if(index==2*n){
        ans.push_back(curr);
        return ;
     }
     if(open<n){
        solve(n,ans,open+1,close,index+1,curr+"(");
     }
     // close 
     if(close<open){
    solve(n,ans,open,close+1,index+1,curr+")");
     }


  }

    vector<string> generateParenthesis(int n) {
       /* 
       open <n
       close <open
       
       */
      vector<string>ans;
      solve(n,ans,0,0,0,"");
      return ans;
    }
};