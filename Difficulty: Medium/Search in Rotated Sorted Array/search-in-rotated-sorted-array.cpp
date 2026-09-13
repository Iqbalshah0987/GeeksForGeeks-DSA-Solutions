class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // Code Here
        int n = arr.size();
        int low=0, high=n-1;
        
        while(low <= high){
            int mid = low + (high-low)/2;
            
            if(arr[mid] == key){
                return mid;
            }
            
            // left part is sorted
            if(arr[low] <= arr[mid]){
                if(arr[low]<=key && key<=arr[mid]){
                    high = mid-1;
                }else{
                    low = mid+1;
                }
            }
            // right part is sorted
            else{
                if(arr[mid]<=key && key<=arr[high]){
                    low = mid+1;
                }else{
                    high = mid-1;
                }
            }
        }
        
        return -1;
    }
};