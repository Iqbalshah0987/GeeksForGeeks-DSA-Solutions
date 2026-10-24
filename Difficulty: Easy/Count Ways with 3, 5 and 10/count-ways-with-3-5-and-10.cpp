
class Solution {
  public:
    // recursion
    int solveRec(vector<int> &score, int sum, int index){
        
        if(sum == 0) return 1;
        if(index >= score.size()) return 0;
        if(sum < 0) return 0;
        
        // take same
        int take = 0;
        if(sum-score[index] >= 0){
            take = solveRec(score, sum-score[index], index);
        }
        
        // take different
        int notake = solveRec(score, sum, index+1);
        
        return take + notake;
    }
    
    // memoization
    int solveMem(vector<int> &score, int sum, int index, vector<vector<int>> &dp){
        
        if(sum == 0) return 1;
        if(index >= score.size()) return 0;
        if(sum < 0) return 0;
        
        if(dp[index][sum] != -1){
            return dp[index][sum];
        }
        
        // take same
        int take = 0;
        if(sum-score[index] >= 0){
            take = solveMem(score, sum-score[index], index, dp);
        }
        
        // take different
        int notake = solveMem(score, sum, index+1, dp);
        
        return dp[index][sum] = take + notake;
    }
    int countWays(int n) {
        //  code here
        vector<int> score = {3, 5, 10};
        
        // return solveRec(score, n, 0);
        
        vector<vector<int>> dp(3, vector<int>(n+1, -1));
        return solveMem(score, n, 0, dp);
    }
};