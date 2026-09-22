class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //we will use min heap
    priority_queue<int , vector<int>,greater<int>>pq;
    int n=nums.size();
    for(int i=0;i<n;i++){
        pq.push(nums[i]);
        while(pq.size()>k){
            pq.pop();

        }
    }
    int m=pq.top();
    return m;
    }
};