class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=INT_MIN;
        int n=prices.size();
        if(n==1)return 0;
        int curr=prices[0];
        for(int i=1;i<n;i++){
            int check =prices[i]-curr;
            maxi=max(maxi,check);
            if(prices[i]<curr)curr=prices[i];
        }
        if(maxi<=0)return 0;
        return maxi;
    }
};