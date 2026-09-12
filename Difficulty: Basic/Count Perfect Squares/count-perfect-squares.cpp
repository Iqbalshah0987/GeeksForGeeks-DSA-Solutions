class Solution {
  public:
    int countSquares(int n) {
        // code here
        
        int count=0;
        for(int i=1; i*i<n; i++){
            count++;
        }
        
        return count;
        
    //     int low=0, high=n;
    //     while(low<=high){
    //         int mid = low + (high-low)/2;
            
    //         if(1LL * mid * mid < n){
    //             low = mid+1;
    //         }else{
    //             high = mid -1;
    //         }
    //     }
        
    //     return high;
        
    }
};