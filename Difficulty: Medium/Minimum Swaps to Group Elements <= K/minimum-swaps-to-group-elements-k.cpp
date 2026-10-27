class Solution {
  public:
    int minSwap(vector<int>& arr, int k) {
        // code here
        
        // find window size
        int window=0;
        for(int num: arr){
            if(num <= k){
                window++;
            }
        }
        
        
        int swaps = 0;
        // check swaps need in first window
        int j=0;
        while(j<window){
            if(arr[j] > k){
                swaps++;
            }
            j++;
        }
        
        int minSwaps = swaps;
        // check other windows
        int i=0;
        while(j<arr.size()){
            if(arr[j] > k){
                swaps++;
            }
            
            if(arr[i] > k){
                swaps--;
            }
            
            minSwaps = min(minSwaps, swaps);
            i++;
            j++;
        }
        
        return minSwaps;
    }
};
