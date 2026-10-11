class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            int index=i+1;
            if(n%index==0){
                int check=nums[i]*nums[i];
                sum+=check;
            }
        }
        return sum;
    }
};