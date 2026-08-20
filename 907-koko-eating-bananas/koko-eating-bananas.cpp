class Solution {
public:

bool istrue(int value,vector<int>&piles, int h){
 long long count=0;
for(auto it :piles){
    if(it<value){
        count++;
    }
    else{
        count += (it + value - 1) / value;
    }
    
}
if(count<=h)return true;
   else return false;

}

    int minEatingSpeed(vector<int>& piles, int h) {
          int maxi=1; int r = *max_element(piles.begin(), piles.end());
; int mini=1;
        
   int ans=1;
        int l=mini; 
        while(l<=r){
  int mid= (l+(r-l)/2); 
     if(istrue(mid,piles,h)){
        ans=mid;
        r=mid-1;
     }
     else{
        l=mid+1;
     }



        }

return ans;

    }
};