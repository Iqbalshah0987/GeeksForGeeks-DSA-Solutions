class Solution {
  public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        
        int n = val.size();
        
        // <perUnitValue, <val, weight>>
        vector<pair<double, pair<int, int>>> unitBasedValues;
        for(int i=0; i<n; i++){
            double perUnitValue = (1.0*val[i]) / wt[i];
            
            unitBasedValues.push_back({perUnitValue, {val[i], wt[i]}});
        }
        
        sort(unitBasedValues.begin(), unitBasedValues.end(), greater<pair<double, pair<int, int>>>());
        
        
        double totalValue = 0.0;
        for(int i=0; i<n; i++){
            double perUnitValue = unitBasedValues[i].first;
            int value = unitBasedValues[i].second.first;
            int weight = unitBasedValues[i].second.second;
            
            if(weight > capacity){
                // we only can take fractional value
                totalValue += 1.0*capacity*perUnitValue;
                capacity=0;
            }else{
                totalValue += value;
                capacity = capacity - weight;
            }
        }
        
        
        return totalValue;
    }
};
