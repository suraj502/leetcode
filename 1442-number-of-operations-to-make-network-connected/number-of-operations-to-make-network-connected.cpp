class Solution {
    public:
    vector<int>parent,sz;
    // find the parent
    int findparent(int n){
        if(parent[n]==n)return n;
        return parent[n]= findparent(parent[n]);
    }
    // use for the union 
    void unit(int u, int v){
        int up=findparent(u);
        int vp=findparent(v);
       if(up==vp)return ;
       if(sz[up]<sz[vp]){
        parent[up]=vp;
        sz[vp]+=sz[up];
       }
        else  {
        parent[vp]=up;
        sz[up]+=sz[vp];
       }
    }
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        int wires=connections.size();
        if(wires<n-1)return -1;
        parent.resize(n);
        sz.resize(n,1);
         for (int i = 0; i < n; i++)
            parent[i] = i;
     for(auto edges:connections){
        int u=edges[0];
        int v=edges[1];
        unit(u,v);
     }
     int ans=0;
     for(int i=0;i<n;i++){
        if(parent[i]==i)ans++;
     }
     return ans-1;
    }
};