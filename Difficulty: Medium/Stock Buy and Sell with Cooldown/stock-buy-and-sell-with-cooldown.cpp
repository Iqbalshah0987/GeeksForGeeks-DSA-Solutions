class Solution {
  public:
    int solveRec(vector<int> &prices, int index, int buy){

        if(index >= prices.size()) return 0;
    
    
        int profit=0;
        if(buy){
            int transationBuy = -prices[index] + solveRec(prices, index+1, 0);
            int skipBuy = 0 + solveRec(prices, index+1, 1);
    
            profit = max(transationBuy, skipBuy);
        }else{
            // increase index by 2 because of cool down time
            int transationSell = +prices[index] + solveRec(prices, index+2, 1);
            int skipSell = 0 + solveRec(prices, index+1, 0);
    
            profit = max(transationSell, skipSell);
        }
    
        return profit;
    }
    
    // memoization
    int solveMem(vector<int> &prices, int index, int buy, vector<vector<int>> &dp){

        if(index >= prices.size()) return 0;
    
        
        if(dp[index][buy] != -1){
            return dp[index][buy];
        }
    
        int profit=0;
        if(buy){
            int transationBuy = -prices[index] + solveMem(prices, index+1, 0, dp);
            int skipBuy = 0 + solveMem(prices, index+1, 1, dp);
    
            profit = max(transationBuy, skipBuy);
        }else{
            // increase index by 2 because of cool down time
            int transationSell = +prices[index] + solveMem(prices, index+2, 1, dp);
            int skipSell = 0 + solveMem(prices, index+1, 0, dp);
    
            profit = max(transationSell, skipSell);
        }
    
        return dp[index][buy] = profit;
    }
    
    int maxProfit(vector<int>& arr) {
        // code here
        
        // return solveRec(arr, 0, 1);
        
        int n = arr.size();
        vector<vector<int>> dp(n+1, vector<int>(2, -1));
        return solveMem(arr, 0, 1, dp);
    }
};