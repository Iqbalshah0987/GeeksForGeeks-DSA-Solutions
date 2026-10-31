class Solution {
  public:
    int solveRec(vector<int> &prices, int index, int buy, int limit, vector<vector<vector<int>>> &dp){
        
        if(index == prices.size()) return 0;
        
        if(limit == 0) return 0;
        
        
        if(dp[index][buy][limit] != -1){
            return dp[index][buy][limit];
        }
        
        int profit=0;
        if(buy){
            int transationBuy = -prices[index] + solveRec(prices, index+1, 0, limit, dp);
            int skipBuy = 0 + solveRec(prices, index+1, 1, limit, dp);
            
            profit = max(transationBuy, skipBuy);
        }else{
            int transationSell = +prices[index] + solveRec(prices, index+1, 1, limit-1, dp);
            int skipSell = 0 + solveRec(prices, index+1, 0, limit, dp);
            
            profit = max(transationSell, skipSell);
        }
        
        return dp[index][buy][limit] = profit;
    }
    int maxProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int k=2;
        
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, -1)));
        return solveRec(prices, 0, 1, k, dp);
    }
};