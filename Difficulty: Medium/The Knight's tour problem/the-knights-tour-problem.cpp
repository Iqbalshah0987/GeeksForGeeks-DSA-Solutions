class Solution {
    // knight's 8 directions
    // 2D1R, 1D2R, 2D1L, 1D2L, 2U1R, 1U2R, 2U1L, 1U2L
    vector<pair<int, int>> directions = {{2,1}, {1,2}, {2,-1}, {1,-2}, {-2,1}, {-1,2}, {-2,-1}, {-1,-2}};
  public:
    bool isvalid(int x, int y, int n, vector<vector<int>> &board){
        if( (x>=0 && x<n) && (y>=0 && y<n) && board[x][y]==-1){
            return true;
        }
        
        return false;
    }
    bool solve(int row, int col, int n, int step, vector<vector<int>> &board){
        if(step == n*n){
            return true;
        }
        
        for(int i=0; i<directions.size(); i++){
            int newrow = row+directions[i].first;
            int newcol = col+directions[i].second;
            
            if(isvalid(newrow, newcol, n, board)){
                board[newrow][newcol] = step;
                
                if(solve(newrow, newcol, n, step+1, board)){
                    return true;
                }
                
                board[newrow][newcol] = -1;
            }
        }
        
        return false;
    }
    vector<vector<int>> knightTour(int n) {
        // code here
        vector<vector<int>> board(n, vector<int>(n, -1));
        board[0][0] = 0;
        
        if(solve(0, 0, n, 1, board)){
            return board;
        }
        
        
        vector<vector<int>> temp;
        return temp;
    }
};