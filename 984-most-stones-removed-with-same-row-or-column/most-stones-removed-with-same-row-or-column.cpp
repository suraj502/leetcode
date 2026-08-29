class Solution {
public:
vector<int>parent;
vector<int>size;
int find(int n) {
    if (parent[n] == n)
        return n;

    return parent[n] = find(parent[n]);
}
void unite(int x, int y) {
    int up = find(x);
    int vp = find(y);

    // Already in same component
    if (up == vp)
        return;

    // Attach smaller component under larger component
    if (size[up] < size[vp])
        swap(up, vp);

    parent[vp] = up;
    size[up] += size[vp];
}
    int removeStones(vector<vector<int>>& stones) {
        int n=stones.size();
        parent.resize(n);
        size.resize(n,1);
        int id=0;
        // for stroing the value of parent and size
        for(auto stone:stones){
            parent[id]=id;
            size[id]=1;
            id++;
        }
// now sir we will be connecting nodes
 for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {

                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1]) {

                    unite(i, j);
                }
            }
        }
int component=0;
for(int i=0;i<n;i++){
    if(parent[i]==i)component++;
}
return n-component;
    }
};