class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int ans=0;
        int n=arr1.size();
        int m=arr2.size();
        for(int i=0 ;i<n;i++){
            int num=arr1[i];
            for(int j=0; j<m;j++){
                int check=abs(num-arr2[j]);
                if(check<=d){
                    ans++;
                    break;
                }
            }
        }
        return n-ans;
    }
};