class Solution {
  public:
    bool isValid(int x, int n, int y, int m, vector<vector<int>> &maze){
        if( (x>=0 && x<n) && (y>=0, y<m) && maze[x][y]==1){
            return true;
        }
        
        return false;
    }
    void solve(int row, int n, int col, int m, vector<string> &ans, vector<vector<int>> &maze, string path){
        if(row == n-1 && col==n-1){
            ans.push_back(path);
            return;
        }
        
        // 4 movements D,L,R,U  
        // (if we already maintain direction in sorted then 
        // we not need sorting in end for conver answer in lexicographical order)
        
        // Down
        if(isValid(row+1, n, col, m, maze)){
            maze[row][col] = 0;
            solve(row+1, n, col, m, ans, maze, path+'D');
            maze[row][col] = 1;
        }
        // Left
        if(isValid(row, n, col-1, m, maze)){
            maze[row][col] = 0;
            solve(row, n, col-1, m, ans, maze, path+'L');
            maze[row][col] = 1;
        }
        // Right
        if(isValid(row, n, col+1, m, maze)){
            maze[row][col] = 0;
            solve(row, n, col+1, m, ans, maze, path+'R');
            maze[row][col] = 1;
        }
        // Up
        if(isValid(row-1, n, col, m, maze)){
            maze[row][col] = 0;
            solve(row-1, n, col, m, ans, maze, path+'U');
            maze[row][col] = 1;
        }
    }
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        vector<string> ans;
        
        if(maze[0][0]==0){
            return ans;
        }
        
        int n = maze.size();
        int m = maze[0].size();
        string path="";
        
        solve(0, n, 0, m, ans, maze, path);
        
        return ans;
    }
};