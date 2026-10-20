class Solution {
  public:
    // Recurtion
    int solveRec(vector<int> &coins, int index, int sum){
        
        if(sum==0){
            return 1;
        }
        
        if(sum < 0 || index==0){
            return 0;
        }
        
        
        // take current again
        int curr_take = solveRec(coins, index, sum-coins[index-1]);
        // leave current and move to next
        int next_take = solveRec(coins, index-1, sum);
        
        return curr_take+next_take;
    }
    
    // memoization
    int solveMem(vector<int> &coins, int index, int sum, vector<vector<int>> &dp){
        
        if(sum==0){
            return 1;
        }
        
        if(sum < 0 || index==0){
            return 0;
        }
        
        
        if(dp[index-1][sum] != -1){
            return dp[index-1][sum];
        }
        
        
        // take current again
        int curr_take = solveMem(coins, index, sum-coins[index-1], dp);
        // leave current and move to next
        int next_take = solveMem(coins, index-1, sum, dp);
        
        dp[index-1][sum] = curr_take+next_take;
        return dp[index-1][sum];
    }
    
    // tabulation
    // int solveRec(vector<int> &coins, int sum){
    //     int n = coins.size();
        
    //     vector<vector<int>> &dp(n+1, vector<int>(sum+1, 0));
        
    //     dp[0][0] = 1;
    //     for(int i=1; i<n; i++){
    //         for(int j=0; j<=sum; j++){
                
    //             // without using current coin
    //             dp[i][j] += dp[i-1][j];
                
    //             // using current coin
    //             if(j - coins[i-1] >= 0){
    //                 dp[i][j] += dp[i][j - coins[i-1]];
    //             }
    //         }
    //     }
        
    //     return dp[n][sum];
    // }
    
    int count(vector<int>& coins, int sum) {
        // code here
        int n = coins.size();
        
        // return  solveRec(coins, n, sum);
        
        
        vector<vector<int>> dp(n, vector<int>(sum+1, -1));
        return  solveMem(coins, n, sum, dp);
        
    }
};