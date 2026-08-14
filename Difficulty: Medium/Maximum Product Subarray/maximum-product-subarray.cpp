class Solution {
  public:
    int maxProduct(vector<int> &arr) {
        // code here
        int n = arr.size();
        int maxprod=INT_MIN, leftprod=1, rightprod=1;
        
        for(int i=0; i<n; i++){
            leftprod *= arr[i];
            rightprod *= arr[n-i-1];
            
            maxprod = max({maxprod, leftprod, rightprod});
            
            if(leftprod==0) leftprod=1;
            if(rightprod==0) rightprod=1;
        }
        
        return maxprod;
    }
};