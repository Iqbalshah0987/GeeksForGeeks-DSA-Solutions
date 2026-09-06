class Solution {
  public:
    int dfs(vector<vector<char>> &mat, int row, int col, string &word, int idx){
        int n = mat.size();
        int m = mat[0].size();
        
        // out of bounds
        if(row<0 || row>=n) return 0;
        if(col<0 || col>=m) return 0;
        
        // character mismatch
        if(mat[row][col] != word[idx]) return 0;
        
        //  complete word found
        if(idx == word.size()-1) return 1;
        
        
        char ch = mat[row][col];
        mat[row][col] = '#';
        int count = 0;
        
        // traverse in 4-directions
        count += dfs(mat, row+1, col, word, idx+1);
        count += dfs(mat, row-1, col, word, idx+1);
        count += dfs(mat, row, col+1, word, idx+1);
        count += dfs(mat, row, col-1, word, idx+1);
        
        mat[row][col] = ch;
        return count;
    }
    int countOccurrence(vector<vector<char>> &mat, string &word) {
        // code here
        int n = mat.size();
        int m = mat[0].size();
        int ans=0;
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans += dfs(mat, i, j, word, 0);
            }
        }
        
        return ans;
    }
};