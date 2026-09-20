class Solution {
  public:
    bool isSafe(int row, int col, vector<string> &board){
        int r=row, c=col;
        
        // top left diagonal
        while(r>=0 && c>=0){
            if(board[r][c] == 'Q') return false;
            r--;
            c--;
        }
        r=row, c=col;
        
        // top vertical
        while(r>=0){
            if(board[r][c] == 'Q') return false;
            r--;
        }
        r=row, c=col;
        
        // top right diagonal
        while(r>=0 && c<board[0].size()){
            if(board[r][c] == 'Q') return false;
            r--;
            c++;
        }
        
        return true;
    }
    void solve(int row, vector<string> &board, vector<int> &temp, vector<vector<int>> &ans){
        if(row >= board.size()){
            ans.push_back(temp);
            return;
        }
        
        for(int col=0; col<board[0].size(); col++){
            
            if(isSafe(row, col, board)){
                temp.push_back(col+1);
                board[row][col] = 'Q';
                
                solve(row+1, board, temp, ans);
                
                temp.pop_back();
                board[row][col] = '.';
            }
        }
    }
    vector<vector<int>> nQueen(int n) {
        // code here
        vector<vector<int>> ans;
        vector<int> temp;
        vector<string> board(n, string(n, '.'));
        
        // check rows wise and put queens in column
        solve(0, board, temp, ans);
        
        return ans;
    }
};