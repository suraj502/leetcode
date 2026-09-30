class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
      int flag=0; // true=0 false=1
      vector<int>ans;
      for(auto it:seq){
        if(it=='('){
           if(flag%2==0) ans.push_back(0);
           else ans.push_back(1);
               
                flag++;
          
            
        }
        else{
             flag--;
            if(flag%2==0) ans.push_back(0);
           else ans.push_back(1);
           
            
        }
      }
return ans;
    }
};