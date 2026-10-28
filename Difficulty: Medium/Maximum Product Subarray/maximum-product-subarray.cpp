class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        int leftProduct=1, rightProduct=1, maxProduct=INT_MIN;
        for(int i=0; i<n; i++){
            leftProduct *= arr[i];
            rightProduct *= arr[n-1-i];
            
            maxProduct = max({maxProduct, leftProduct, rightProduct});
            
            if(leftProduct==0) leftProduct=1;
            if(rightProduct==0) rightProduct=1;
        }
        
        return maxProduct;
    }
};