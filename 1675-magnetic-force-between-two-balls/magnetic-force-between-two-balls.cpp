class Solution {
public:
   bool possible(int mid, vector<int>& position, int m) {
    int balls = 1;
    int last = position[0];

    for (int i = 1; i < position.size(); i++) {

        if (position[i] - last >= mid) {
            balls++;
            last = position[i];
        }

        if (balls >= m)
            return true;
    }

    return false;
}

    int maxDistance(vector<int>& position, int m) {
      int  mini=0;
      sort(position.begin(), position.end());
      int n=position.size();
      int low=1; int high = position[n - 1] - position[0];
      while(low<=high){
     int mid=(low+high)/2;
     if(possible(mid,position,m)){
low=mid+1;
mini=mid;
}
else{
    high=mid-1;
}

      } 
      
return mini;
    }
};