class Solution {
  public:
    vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
        // Code here
        
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        ans.push_back(arr[0]);
        int index=0;
        
        for(int i=1; i<arr.size(); i++){
            
            if(arr[i][0] <= ans[index][1]){
                ans[index][0] = min(ans[index][0], arr[i][0]);
                ans[index][1] = max(ans[index][1], arr[i][1]);
            }else{
                ans.push_back(arr[i]);
                index++;
            }
        }
        
        return ans;
    }
};