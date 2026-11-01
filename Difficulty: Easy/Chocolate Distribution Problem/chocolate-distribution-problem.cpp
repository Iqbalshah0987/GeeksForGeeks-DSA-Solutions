class Solution {
  public:
    int findMinDiff(vector<int>& a, int m) {
        // code here
        
        sort(a.begin(), a.end());
        
        int ans=INT_MAX;
        int i=0, j=m-1;
        while(j<a.size()){
            ans = min(ans, a[j]-a[i]);
            i++; j++;
        }
        
        return ans;
    }
};