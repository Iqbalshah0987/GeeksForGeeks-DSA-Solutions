class Solution {
  public:
    int maxWater(vector<int> &arr) {
        // code here
        int n = arr.size();
        
        vector<int> prefix(n,0), suffix(n,0);
        prefix[0] = arr[0];
        suffix[n-1] = arr[n-1];
        
        for(int i=1; i<n; i++){
            prefix[i] = max(prefix[i-1], arr[i]);
            suffix[n-i-1] = max(arr[n-i-1], suffix[n-i]);
        }
        
        int units=0;
        for(int i=0; i<n; i++){
            units += abs(arr[i] - min(prefix[i], suffix[i]));
        }
        
        return units;
    }
};