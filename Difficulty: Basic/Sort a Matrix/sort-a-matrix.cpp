class Solution {
  public:
    vector<vector<int>> sortedMatrix(vector<vector<int>> mat) {
        // code here
        int row=mat.size(), col=mat[0].size();
        
        vector<int> temp;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                temp.push_back(mat[i][j]);
            }
        }
        sort(temp.begin(), temp.end());
        
        int index=0;
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                mat[i][j] = temp[index++];
            }
        }
        
        return mat;
    }
};