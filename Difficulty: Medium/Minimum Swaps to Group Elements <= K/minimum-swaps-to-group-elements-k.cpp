class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        int n = arr.size();
        
        // step 1: find all elements <= k
        int window=0;
        for(int num: arr){
            if(num<=k){
                window++;
            }
        }
        
        // step 2: find elements > k in window size
        int minSwap=0;
        for(int i=0; i<window; i++){
            if(arr[i] > k){
                minSwap++;
            }
        }
        
        // step 3: find elements > k in every window and store in minSwap
        int i=0, j=window, swap=minSwap;
        while(j<n){
            if(arr[i]>k){
                swap--;
            }
            if(arr[j]>k){
                swap++;
            }
            
            minSwap = min(minSwap, swap);
            i++;
            j++;
        }
        
        return minSwap;
    }
};
