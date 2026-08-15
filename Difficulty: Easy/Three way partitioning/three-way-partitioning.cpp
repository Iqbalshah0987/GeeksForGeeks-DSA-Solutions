class Solution {
  public:
    // Function to partition the array around the range such
    // that array is divided into three parts.
    void threeWayPartition(vector<int>& arr, int a, int b) {
        // code here
        int i=0, j=0, k=arr.size()-1;
        
        while(j<=k){
            if(arr[j] < a){
                swap(arr[i], arr[j]);
                i++; j++;
            }else if(a<=arr[j] && arr[j]<=b){
                j++;
            }else{
                swap(arr[j], arr[k]);
                k--;
            }
        }
    }
};