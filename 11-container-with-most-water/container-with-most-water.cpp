class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        if(n==2){
            int h=min(height[0],height[1]);
            return h*1;
        }
        int l=0; int r=n-1; int maxi=-1;
        while(l<r){
            if(height[l]<height[r]){
                int cal=(height[l])*(r-l);
                maxi=max(maxi,cal);
                l++;
            }
            else{
                int cal=(height[r])*(r-l);
                maxi=max(maxi,cal);
                r--;
            }
        }
        return maxi;
    }
};