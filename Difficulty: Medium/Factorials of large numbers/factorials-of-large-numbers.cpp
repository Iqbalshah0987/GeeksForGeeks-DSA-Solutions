class Solution {
  public:
    vector<int> factorial(int n) {
        // code here
        vector<int> fact;
        fact.push_back(1);
        
        for(int i=1; i<=n; i++){
            
            int carry=0;
            for(int j=0; j<fact.size(); j++){
                int prod = (fact[j]*i) + carry;
                
                fact[j] = prod%10;
                carry = prod/10;
            }
            
            while(carry){
                fact.push_back(carry%10);
                carry /= 10;
            }
        }
        
        reverse(fact.begin(), fact.end());
        
        return fact;
    }
};