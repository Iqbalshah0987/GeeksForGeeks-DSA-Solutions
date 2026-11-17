class Solution {
  public:
    void threeWayPartition(vector<int>& arr, int a, int b) {
        // code here
        
        int n = arr.size();
        int i=0, j=0, k=n-1;
        
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