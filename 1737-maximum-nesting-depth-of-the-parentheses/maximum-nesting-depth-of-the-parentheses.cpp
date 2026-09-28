class Solution {
public:
    int maxDepth(string s) {
        int count =-1;int cnt=0;
         for(auto it :s){
            if(it=='('){
                cnt++;
                count=max(count,cnt);
            }
            else if(it==')')cnt--;
         }
         if(count==-1)return 0;
         return count;
    }
};