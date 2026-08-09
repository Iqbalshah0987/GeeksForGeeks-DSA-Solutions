class Solution {
  public:
    vector<int> getMinMax(vector<int> &arr) {
        // code here
        int mini=INT_MAX, maxi = INT_MIN;
        
        for(int i=0; i<arr.size(); i++){
            mini = min(mini, arr[i]);
            maxi = max(maxi, arr[i]);
        }
        
        return {mini, maxi};
    }
};