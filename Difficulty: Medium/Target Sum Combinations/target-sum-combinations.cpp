class Solution {
  public:
    void solve(vector<int> &arr, int index, int target, vector<int> &curr, vector<vector<int>> &ans){
        if(target == 0){
            ans.push_back(curr);
            return;
        }
        
        if(target <0 || index >=arr.size()){
            return;
        }
        
        curr.push_back(arr[index]);
        
        // call with same index
        solve(arr, index, target-arr[index], curr, ans);
        curr.pop_back();
        
        // call with increase index
        solve(arr, index+1, target, curr, ans);
    }
    vector<vector<int>> targetSumComb(vector<int> &arr, int target) {
        // code here
        vector<vector<int>> ans;
        vector<int> curr;
        
        solve(arr, 0, target, curr, ans);
        
        return ans;
    }
};