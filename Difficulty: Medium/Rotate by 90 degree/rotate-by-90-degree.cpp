class Solution {
  public:
    void rotateMatrix(vector<vector<int>>& mat) {
        // code here
        int row=mat.size(), col=mat[0].size();
        
        for(int i=0; i<row; i++){
            for(int j=i+1; j<col; j++){
                if(i!=j){
                    swap(mat[i][j], mat[j][i]);
                }
            }
        }
        
        reverse(mat.begin(), mat.end());
    }
};
