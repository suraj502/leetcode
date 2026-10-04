class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // size
        int sz=0;
        for(auto it:nums){
            if(it!=val)sz++;
        }
        // change array
        int k=0;
        for (auto it:nums){
            if(it!=val){
                nums[k]=it;
                k++;
            }
        }
        return sz;
    }
};