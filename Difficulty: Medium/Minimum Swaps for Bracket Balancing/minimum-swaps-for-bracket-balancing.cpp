class Solution {
  public:
    int minimumNumberOfSwaps(string& s) {
        // code here
        
        int open=0, close=0, unbalanced=0, swaps=0;
        for(char ch: s){
            if(ch=='['){
                open++;
                
                if(unbalanced>0){
                    swaps += unbalanced;
                    unbalanced--;
                }
            }else{
                close++;
                
                unbalanced = close-open;
            }
        }
        
        return swaps;
    }
};