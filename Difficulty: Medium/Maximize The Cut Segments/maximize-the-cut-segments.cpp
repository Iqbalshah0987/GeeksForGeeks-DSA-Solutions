class Solution {
  public:
    // recursion
    int solveRec(int n, int x, int y, int z){
        
        if(n==0) return 0;
        
        if(n<0) return INT_MIN;
        
        int a = solveRec(n-x, x, y, z) + 1;
        int b = solveRec(n-y, x, y, z) + 1;
        int c = solveRec(n-z, x, y, z) + 1;
        
        return max({a, b, c});
    }
    
    // memoization
    int solveMem(int n, int x, int y, int z, vector<int> &dp){
        
        if(n==0) return 0;
        
        if(n<0) return INT_MIN;
        
        if(dp[n] != -1){
            return dp[n];
        }
        
        int a = solveMem(n-x, x, y, z, dp) + 1;
        int b = solveMem(n-y, x, y, z, dp) + 1;
        int c = solveMem(n-z, x, y, z, dp) + 1;
        
        return dp[n] = max({a, b, c});
    }
    int maximizeCuts(int n, int x, int y, int z) {
        // code here
        
        // return solveRec(n, x, y, z);
        
        vector<int> dp(n+1, -1);
        int ans = solveMem(n, x, y, z, dp);
        return (ans < 0)? 0: ans;
    }
};