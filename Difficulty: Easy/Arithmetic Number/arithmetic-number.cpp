class Solution {
  public:
    int inSequence(int a, int b, int c) {
        // code here
        
        // Tn = a + (n-1)*d
        // b = a + (n-1)*c
        // b-a = (n-1)*c
        // now we need to check completely divisible and n>=0 so
        
        return (b-a)%c==0 && (b-a)/c>=0;
    }
};