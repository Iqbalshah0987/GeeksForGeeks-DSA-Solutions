class Solution {
  public:
    int solveRec(vector<int> &prices, int index, bool buy, int limit){

        if(index == prices.size()) return 0;

        if(limit == 0) return 0;

        int profit=0;
        if(buy){
            int transationBuy = -prices[index] + solveRec(prices, index+1, false, limit);
            int skipBuy = 0 + solveRec(prices, index+1, true, limit);

            profit = max(transationBuy, skipBuy);
        }else{
            int transationSell = +prices[index] + solveRec(prices, index+1, true, limit-1);
            int skipSell = 0 + solveRec(prices, index+1, false, limit);

            profit = max(transationSell, skipSell);
        }

        return profit;
    }

    // memoization
    int solveMem(vector<int> &prices, int index, int buy, int limit, vector<vector<vector<int>>> &dp){

        if(index == prices.size()) return 0;

        if(limit == 0) return 0;


        if(dp[index][buy][limit] != -1){
            return dp[index][buy][limit];
        }

        int profit=0;
        if(buy){
            int transationBuy = -prices[index] + solveMem(prices, index+1, 0, limit, dp);
            int skipBuy = 0 + solveMem(prices, index+1, 1, limit, dp);

            profit = max(transationBuy, skipBuy);
        }else{
            int transationSell = +prices[index] + solveMem(prices, index+1, 1, limit-1, dp);
            int skipSell = 0 + solveMem(prices, index+1, 0, limit, dp);

            profit = max(transationSell, skipSell);
        }

        return dp[index][buy][limit] = profit;
    }

    // tabulation
    int solveTab(vector<int> &prices, int k){

        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=k; limit++){

                    int profit=0;
                    if(buy){
                        int transationBuy = -prices[index] + dp[index+1][0][limit];
                        int skipBuy = 0 + dp[index+1][1][limit];

                        profit = max(transationBuy, skipBuy);
                    }else{
                        int transationSell = +prices[index] + dp[index+1][1][limit-1];
                        int skipSell = 0 + dp[index+1][0][limit];

                        profit = max(transationSell, skipSell);
                    }

                    dp[index][buy][limit] = profit;
                }
            }
        }

        return dp[0][1][k];
    }

    // space optimization
    int solveSpacOpt(vector<int> &prices, int k){

        int n = prices.size();
        // vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
        vector<vector<int>> curr(2, vector<int>(k+1, 0));
        vector<vector<int>> next(2, vector<int>(k+1, 0));

        for(int index=n-1; index>=0; index--){
            for(int buy=0; buy<=1; buy++){
                for(int limit=1; limit<=k; limit++){

                    int profit=0;
                    if(buy){
                        int transationBuy = -prices[index] + next[0][limit];
                        int skipBuy = 0 + next[1][limit];

                        profit = max(transationBuy, skipBuy);
                    }else{
                        int transationSell = +prices[index] + next[1][limit-1];
                        int skipSell = 0 + next[0][limit];

                        profit = max(transationSell, skipSell);
                    }

                    curr[buy][limit] = profit;
                }
            }

            next = curr;
        }

        return next[1][k];
    }
    
    
    int maxProfit(vector<int>& prices, int k) {
        // code here
        
        // return solveRec(prices, 0, true, k);


        // int n = prices.size();
        // vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(k+1, -1)));
        // return solveMem(prices, 0, 1, k, dp);


        // return solveTab(prices, k);


        return solveSpacOpt(prices, k);
    }
};