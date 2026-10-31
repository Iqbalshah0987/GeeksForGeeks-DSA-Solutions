class Solution {
  public:
    int solveRec(vector<int> &prices, int index, int operationNumber, int k){

        if(index == prices.size()) return 0;

        if(operationNumber == 2*k) return 0;

        int profit=0;
        if(operationNumber%2 == 0){
            int transationBuy = -prices[index] + solveRec(prices, index+1, operationNumber+1, k);
            int skipBuy = 0 + solveRec(prices, index+1, operationNumber, k);

            profit = max(transationBuy, skipBuy);
        }else{
            int transationSell = +prices[index] + solveRec(prices, index+1, operationNumber+1, k);
            int skipSell = 0 + solveRec(prices, index+1, operationNumber, k);

            profit = max(transationSell, skipSell);
        }

        return profit;
    }
    
    // memoization
    int solveMem(vector<int> &prices, int index, int operationNumber, int k, vector<vector<int>> &dp){

        if(index == prices.size()) return 0;

        if(operationNumber == 2*k) return 0;


        if(dp[index][operationNumber] != -1){
            return dp[index][operationNumber];
        }
        
        
        int profit=0;
        if(operationNumber%2 == 0){
            int transationBuy = -prices[index] + solveMem(prices, index+1, operationNumber+1, k, dp);
            int skipBuy = 0 + solveMem(prices, index+1, operationNumber, k, dp);

            profit = max(transationBuy, skipBuy);
        }else{
            int transationSell = +prices[index] + solveMem(prices, index+1, operationNumber+1, k, dp);
            int skipSell = 0 + solveMem(prices, index+1, operationNumber, k, dp);

            profit = max(transationSell, skipSell);
        }

        return dp[index][operationNumber] = profit;
    }
    
    int maxProfit(vector<int>& prices, int k) {
        // code here
        
        // return solveRec(prices, 0, 0, k);

        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2*k, -1));
        return solveMem(prices, 0, 0, k, dp);
    }
};