class Solution {
  public:
    // recursion
    int solveRec(vector<int> &cost, int w, int index){
        
        if(w == 0) return 0;
        if(index >= cost.size()) return INT_MAX;
        if(cost[index] == -1) {
            return solveRec(cost, w, index+1);
        };
        
        
        // take the current cost and again go for same cost
        int take = INT_MAX;
        if(w-(index+1) >= 0){
            int subproblem = solveRec(cost, w-(index+1), index);
            if(subproblem != INT_MAX){
                take = cost[index] + subproblem;
            }
        }
        
        // don't take the current cost and move to next cost
        int notake = solveRec(cost, w, index+1);
        
        return min(take, notake);
    }
    
    // memoization
    int solveMem(vector<int> &cost, int w, int index, vector<vector<int>> &dp){
        
        if(w == 0) return 0;
        if(index >= cost.size()) return INT_MAX;
        
        if(dp[index][w] != -1){
            return dp[index][w];
        }
        
        if(cost[index] == -1) {
            return solveMem(cost, w, index+1, dp);
        };
        
        
        // take the current cost and again go for same cost
        int take = INT_MAX;
        if(w-(index+1) >= 0){
            int subproblem = solveMem(cost, w-(index+1), index, dp);
            if(subproblem != INT_MAX){
                take = cost[index] + subproblem;
            }
        }
        
        // don't take the current cost and move to next cost
        int notake = solveMem(cost, w, index+1, dp);
        
        return dp[index][w] = min(take, notake);
    }
    
    int minimumCost(vector<int> &cost, int w) {
        // code here
        
        // int ans = solveRec(cost, w, 0);
        // return ans==INT_MAX? -1: ans;
        
        
        int n = cost.size();
        vector<vector<int>> dp(n, vector<int>(w+1, -1));
        int ans = solveMem(cost, w, 0, dp);
        return ans==INT_MAX? -1: ans;
    }
};
