class Solution {
  public:
    void solve(int i, int j, vector<vector<int>>& mat, vector<int> &path, vector<vector<int>>& paths){
        int m = mat.size();
        int n = mat[0].size();
        
        path.push_back(mat[i][j]);
        
        if(i==m-1 && j==n-1){
            paths.push_back(path);
        }else{
            // mvoe right
            if(j+1<n){
                solve(i, j+1, mat, path, paths);
            }
            // move down
            if(i+1<m){
                solve(i+1, j, mat, path, paths);
            }
        }
        
        path.pop_back();
    }
    vector<vector<int>> allPaths(vector<vector<int>>& mat) {
        // code here
        vector<vector<int>> paths;
        vector<int> path;
        
        solve(0, 0, mat, path, paths);
        
        return paths;
    }
};