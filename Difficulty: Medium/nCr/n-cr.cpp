class Solution {
  public:
    int nCr(int n, int r) {
        // code here
        
        if(r > n){
            return 0;
        }
        
        
        r = min(r, n-r);
        
        long long fact = 1;
        for(int i=0; i<r; i++){
            fact = fact * (n-i)/(i+1);
        }
        
        return (int)fact;
    }
};