class Solution {
  public:
    bool isSafe(vector<vector<int>> &mat, int row, int col, int num){
        
        for(int i=0; i<9; i++){
            // check in every row
            if(mat[i][col] == num) return false;
            // check in every col
            if(mat[row][i] == num) return false;
        }
        
        
        // check in 3x3 matrics
        int startrow = (row/3)*3;
        int startcol = (col/3)*3;
        for(int i=startrow; i<startrow+3; i++){
            for(int j=startcol; j<startcol+3; j++){
                if(mat[i][j] == num) return false;
            }
        }
        
        return true;
    }
    bool solve(vector<vector<int>> &mat, int row, int col){
        if(row==9) return true;
        
        int nextrow=0, nextcol=0;
        if(col==8){
            nextrow = row+1;
            nextcol = 0;
        }else{
            nextrow = row;
            nextcol = col+1;
        }
        
        if(mat[row][col] != 0){
            return solve(mat, nextrow, nextcol);
        }else{
            for(int k=1; k<=9; k++){
                if(isSafe(mat, row, col, k)){
                    mat[row][col] = k;
                    
                    if(solve(mat, nextrow, nextcol)) return true;
                    
                    mat[row][col] = 0;
                }
            }
            return false;
        }
        
        return true;
    }
    void solveSudoku(vector<vector<int>> &mat) {
        // code here
        solve(mat, 0, 0);
    }
};