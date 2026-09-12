class Solution {
  public:
    int lowerBound(vector<int> &arr, int x){
        int n = arr.size();
        int low=0, high = n;
        
        while(low < high){
            int mid = low + (high-low)/2;
            
            if(arr[mid] >= x){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        
        return low;
    }
    int upperBound(vector<int> &arr, int x){
        int n = arr.size();
        int low=0, high = n;
        
        while(low < high){
            int mid = low + (high-low)/2;
            
            if(arr[mid] > x){
                high = mid;
            }else{
                low = mid+1;
            }
        }
        
        return low;
    }
    vector<int> find(vector<int>& arr, int x) {
        // code here
        
        int start = lowerBound(arr, x);
        if(start == arr.size() || arr[start]!=x){
            return {-1, -1};
        }
        
        int end = upperBound(arr, x);
        
        return {start, end-1};
    }
};