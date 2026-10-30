class Solution {
  public:
    int maxProfit(vector<int> &prices) {
        // code here
        
        int profit=0;
        
        int min_price = prices[0];
        for(int i=1; i<prices.size(); i++){
            
            if(min_price < prices[i]){
                profit = max(profit, prices[i]-min_price);
            }
            
            min_price = min(min_price, prices[i]);
        }
        
        return profit;
    }
};
