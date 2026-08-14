class Solution {
  public:
    int smallestSubWithSum(int x, vector<int>& arr) {
        // code here
        
        int n = arr.size();
        int i=0, j=0, sum=0, maxele=INT_MAX;
        
        while(j<n){
            sum += arr[j];
            
            if(sum > x){
                maxele = min(maxele, j-i+1);
                
                while(i<=j && sum-arr[i] > x){
                    sum -= arr[i++];
                    maxele = min(maxele, j-i+1);
                }
            }
            
            j++;
        }
        
        return maxele==INT_MAX ? 0: maxele;
    }
};