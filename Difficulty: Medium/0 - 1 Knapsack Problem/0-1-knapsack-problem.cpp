class Solution {
  public:
    // recursion
    int solveRec(int capacity, vector<int> &wt, vector<int> &val, int index){
        
        if(index == 0){
            if(wt[index] <= capacity){
                return val[index];
            }else{
                return 0;
            }
        }
        
        
        
        // pick value if
        int include = 0;
        if(wt[index] <= capacity){
            include = val[index] + solveRec(capacity-wt[index], wt, val, index-1);
        }
        
        // don't pick
        int exclude = solveRec(capacity, wt, val, index-1);
        
        return max(include, exclude);
    }
    
    // memoization
    int solveMem(int capacity, vector<int> &wt, vector<int> &val, int index, vector<vector<int>> &dp){
        
        if(index == 0){
            if(wt[index] <= capacity){
                return val[index];
            }else{
                return 0;
            }
        }
        
        
        if(dp[index][capacity] != -1){
            return dp[index][capacity];
        }
        
        // pick value if
        int include = 0;
        if(wt[index] <= capacity){
            include = val[index] + solveMem(capacity-wt[index], wt, val, index-1, dp);
        }
        
        // don't pick
        int exclude = solveMem(capacity, wt, val, index-1, dp);
        
        dp[index][capacity] = max(include, exclude);
        return dp[index][capacity];
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        
        // return solveRec(W, wt, val, wt.size()-1);
        
        
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(W+1, -1));
        return solveMem(W, wt, val, n-1, dp);
        
    }
};