class Solution {
public:
    int minAddToMakeValid(string s) {
       int cnt=0; int check=0;
       for (auto it :s){
        if(it=='(')cnt++;
        else {
            cnt--;
          if(cnt<0){
            check++;
            cnt=0;
          }
        }


       } 
       return check+cnt;
    }
};