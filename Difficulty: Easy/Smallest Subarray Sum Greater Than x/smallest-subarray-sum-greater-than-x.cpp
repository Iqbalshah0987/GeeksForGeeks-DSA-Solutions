class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // code here
        
        int subarrayCount = INT_MAX, sum=0;
        int i=0, j=0, n=arr.size();
        
        while(j<n){
            sum += arr[j];
            
            if(sum > x){
                // now reduce i
                while(i<=j && sum-arr[i] > x){
                    sum -= arr[i];
                    i++;
                }
                
                subarrayCount = min(subarrayCount, j-i+1);
            }
            j++;
        }
        
        return subarrayCount==INT_MAX?0 :subarrayCount;
    }
};