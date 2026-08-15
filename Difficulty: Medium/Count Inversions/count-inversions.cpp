class Solution {
  public:
    int merge(vector<int> &arr, int low, int mid, int high){
        vector<int> temp;
        int left = low, right=mid+1;
        int res=0;
        
        while(left<=mid && right<=high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left++]);
            }else{
                temp.push_back(arr[right++]);
                res += mid-left+1;
            }
        }
        
        while(left<=mid){
            temp.push_back(arr[left++]);
        }
        while(right<=high){
            temp.push_back(arr[right++]);
        }
        
        for(int i=0; i<temp.size(); i++){
            arr[low+i] = temp[i];
        }
        
        return res;
    }
    int mergeSort(vector<int> &arr, int low, int high){
        int res = 0;
        if(low >= high) return res;
        
        int mid = low + (high-low)/2;
        res += mergeSort(arr, low, mid);
        res += mergeSort(arr, mid+1, high);
        res += merge(arr, low, mid, high);
        
        return res;
    }
    int inversionCount(vector<int> &arr) {
        // code here
        return mergeSort(arr, 0, arr.size()-1);
    }
};