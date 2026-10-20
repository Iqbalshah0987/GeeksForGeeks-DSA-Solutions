class Solution {
  public:
    int solveRec(vector<int> &coins, int sum){

        if(sum==0){
            return 0;
        }

        if(sum < 0){
            return INT_MAX;
        }

        
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int ans = solveRec(coins, sum-coins[i]);
            
            if(ans != INT_MAX){
                mini = min(mini, ans+1);
            }
        }
        
        return mini;
    }
    
    int solveMem(vector<int> &coins, int sum, vector<int> &dp){

        if(sum==0){
            return 0;
        }

        if(sum < 0){
            return INT_MAX;
        }


        if(dp[sum] != -1){
            return dp[sum];
        }
        
        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++){
            int ans = solveMem(coins, sum-coins[i], dp);
            
            if(ans != INT_MAX){
                mini = min(mini, ans+1);
            }
        }
        
        // step 2
        dp[sum] = mini;
        
        return mini;
    }
    
    int findMin(int n) {
        // code here
        vector<int> coins = {1, 2, 5, 10};
        int size = coins.size();
        // int ans = solveRec(coins, n);
        // if(ans == INT_MAX) return -1;
        // return ans;
        
        
        // step 1
        vector<int> dp(n+1, -1);
        int ans = solveMem(coins, n, dp);
        if(ans == INT_MAX) return -1;
        return ans;
    }
};