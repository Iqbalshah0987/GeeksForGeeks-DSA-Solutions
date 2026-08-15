class Solution {
  public:
    int getMinDiff(vector<int> &arr, int k) {
        // code here
        sort(arr.begin(), arr.end());
        int n = arr.size();
        
        int ans = arr[n-1]-arr[0];
        int smallest = arr[0]+k;
        int largest = arr[n-1]-k;
        
        for(int i=1; i<n; i++){
            int minH = min(smallest, arr[i]-k);
            int maxH = max(largest, arr[i-1]+k);
            
            if(minH < 0) continue;
            
            ans = min(ans, maxH-minH);
        }
        
        return ans;
    }
};