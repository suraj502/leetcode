class Solution {
public:
    bool search(vector<int>& arr, int key) {
         int low =0; int high=arr.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(arr[mid]==key)return true;
            if(arr[low]==arr[mid] && arr[mid]==arr[high]){
    low++;
    high--;
    continue;
}
            if(arr[low]<=arr[mid]){
                // chcwk for target
                if(arr[low]<=key && arr[mid]>=key){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
                
            }
            else{
                if(arr[mid+1]<=key && arr[high]>=key){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return false;
    }
};