class Solution {
  public:
    int solveRec(int n){
        
        if(n == 1) return 0;
        if(n == 2) return 1;
        
        return (n-1) * (solveRec(n-2) + solveRec(n-1));
    }
    int derangeCount(int n) {
        // code here
        return solveRec(n);
    }
};