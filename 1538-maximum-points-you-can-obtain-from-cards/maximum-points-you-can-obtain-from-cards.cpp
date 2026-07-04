class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int ls=0;
         int rs=0; 
         int n=cardPoints.size();
         for(int i=0;i<k;i++){
            ls+=cardPoints[i];

         }
         int maxi=ls;
         int z=n-1;
         for (int j=k-1;j>=0;j--){
          ls=ls-cardPoints[j];
          rs+=cardPoints[z];
          maxi=max(maxi,ls+rs);
          z--;
         
    }
    return maxi;
    }
};