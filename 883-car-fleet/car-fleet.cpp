class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=speed.size();
        vector<pair<int,double>>mp;
        for(int i=0;i<n;i++){
            double curr=(double)(target-position[i])/speed[i];
            mp.push_back({position[i],curr});
        }
 sort(mp.begin(),mp.end());
 stack<double>st;
   for(int i=n-1;i>=0;i--){
    double cut=mp[i].second;
 
if(st.empty()||cut>st.top()){
    st.push(cut);
}



   }
return st.size();

    }
};