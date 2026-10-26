class Solution {
  public:
    int partition(vector<int> &arr, int low, int high){
        int pivot = arr[high];
        int i=low;
        
        for(int j=low; j<high; j++){
            if(arr[j] < pivot){
                swap(arr[i], arr[j]);
                i++;
            }
        }
        
        swap(arr[i], arr[high]);
        return i;
    }
    int quickSelect(vector<int> &arr, int low, int high, int k){
        
        if(low <= high){
            
            int pivot = partition(arr, low, high);
            if(pivot == k){
                return arr[pivot];
            }else if(pivot < k){
                return quickSelect(arr, pivot+1, high, k);
            }else{
                return quickSelect(arr, low, pivot-1, k);
            }
            
        }
        
    }
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        return quickSelect(arr, 0, arr.size()-1, k-1);
    }
};