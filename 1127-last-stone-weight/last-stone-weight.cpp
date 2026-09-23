class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        // max heap
        priority_queue<int>pq;
        int n=stones.size();
        if(n==1)return stones[0];
        for (int i=0;i<n;i++){
            pq.push(stones[i]);
        }
        // till pq.size >1
        int ans=0;
        while(pq.size()>1){
            int x=pq.top();
            pq.pop();
            int y=pq.top();
            pq.pop();
            if(x==y)continue;
            else{
                int wt=x-y;
             pq.push(wt);
            }
        }
        if(pq.size()==0)return 0;
        else return pq.top();
    }
};