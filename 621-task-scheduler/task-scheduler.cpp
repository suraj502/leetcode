class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int freq[26]={0};
        int m=tasks.size();
        for(int i=0;i<m;i++){
            freq[tasks[i]-'A']++;
        }
        // making priority queue;
        priority_queue<int>pq;
        for (auto it:freq){
            if(it>0) pq.push(it);
         
        }
        // now we make one count 
        int time=0;
        queue<pair<int,int>>q;
        while(!pq.empty()|| !q.empty()){
           time ++;
           // push from queue
           if(!q.empty() && q.front().second==time){
            pq.push(q.front().first);
            q.pop();
           }
           // excute 
           if(!pq.empty()){
            int f=pq.top();
            pq.pop();
            f--;
            if(f>0){
                q.push({f,time+n+1});
            }
           }
           


        }
return time;
    }
};