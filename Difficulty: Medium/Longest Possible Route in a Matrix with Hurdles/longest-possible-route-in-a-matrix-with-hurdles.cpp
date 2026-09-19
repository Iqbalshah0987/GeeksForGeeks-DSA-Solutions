class Solution {
    vector<pair<int, int>> dir = {{1, 0}, {0, -1}, {0, 1}, {-1, 0}};
  public:
    int solve(vector<vector<int>> &mat, int i, int j, int x, int y) {
        int m = mat.size();
        int n = mat[0].size();

        if(i==x && j==y){
            return 0;
        }

        if (i < 0 || i >= m || j < 0 || j >= n || mat[i][j] == 0) {
            return -1;
        }

        mat[i][j] = 0;
        
        int maxPath = -1;

        // Try all four directions
        for (int k = 0; k < dir.size(); k++) {
            int ni = i + dir[k].first;
            int nj = j + dir[k].second;

            int pathLength = solve(mat, ni, nj, x, y);
            if (pathLength != -1) {
                maxPath = max(maxPath, 1 + pathLength);
            }
        }

        // Backtrack - unmark current cell
        mat[i][j] = 1;

        return maxPath;
    }
    int longestPath(vector<vector<int>>& mat, int xs, int ys, int xd, int yd) {
        // code here
        
        // when source and destination are blocked
        if(mat[xs][ys]==0 || mat[xd][yd]==0){
            return -1;
        }
        
        return solve(mat, xs, ys, xd, yd);
    }
};