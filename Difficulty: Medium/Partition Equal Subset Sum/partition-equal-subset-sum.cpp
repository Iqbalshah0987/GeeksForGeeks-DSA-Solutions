class Solution {
  public:
    // recursion
    bool solveRec(vector<int> &arr, int index, int sum){
        
        if(sum == 0) return true;
        if(index >= arr.size()) return false;
        if(sum < 0) return false;
        
        
        // take the element and move to next
        bool take=false;
        if(sum-arr[index] >= 0){
            take = solveRec(arr, index+1, sum-arr[index]);
        }
        
        // don't take the element and move to next
        bool notake = solveRec(arr, index+1, sum);
        
        return take || notake;
    }
    
    // memoization
    bool solveMem(vector<int> &arr, int index, int sum, vector<vector<int>> &dp){
        
        if(sum == 0) return true;
        if(index >= arr.size()) return false;
        if(sum < 0) return false;
        
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        
        // take the element and move to next
        bool take=false;
        if(sum-arr[index] >= 0){
            take = solveMem(arr, index+1, sum-arr[index], dp);
        }
        
        // don't take the element and move to next
        bool notake = solveMem(arr, index+1, sum, dp);
        
        return dp[index][sum] = take || notake;
    }
    bool equalPartition(vector<int>& arr) {
        // code here
        
        // int sum = accumulate(arr.begin(), arr.end(), 0);
        // if(sum%2 == 1) return false;
        // return solveRec(arr, 0, sum/2);
        
        
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        if(sum%2 == 1) return false;
        
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return solveMem(arr, 0, sum/2, dp);
        
        
    }
};