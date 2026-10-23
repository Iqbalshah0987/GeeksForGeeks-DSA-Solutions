class Solution {
  public:
    // recursion
    int solveRec(int capacity, vector<int> &wt, vector<int> &val, int index){

        if(index == val.size()) return 0;


        // pick value if
        int take = 0;
        if(wt[index] <= capacity){
            take = val[index] + solveRec(capacity-wt[index], wt, val, index);
        }

        // don't pick
        int notake = solveRec(capacity, wt, val, index+1);

        return max(take, notake);
    }
    
    // memoization
    int solveMem(int capacity, vector<int> &wt, vector<int> &val, int index, vector<vector<int>> &dp){

        if(index == val.size()) return 0;

        if(dp[index][capacity] != -1){
            return dp[index][capacity];
        }

        // pick value if
        int take = 0;
        if(wt[index] <= capacity){
            take = val[index] + solveMem(capacity-wt[index], wt, val, index, dp);
        }

        // don't pick
        int notake = solveMem(capacity, wt, val, index+1, dp);

        return dp[index][capacity] = max(take, notake);
    }
    
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        // return solveRec(capacity, wt, val, 0);
        
        
        int n = wt.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
        return solveMem(capacity, wt, val, 0, dp);
    }
};