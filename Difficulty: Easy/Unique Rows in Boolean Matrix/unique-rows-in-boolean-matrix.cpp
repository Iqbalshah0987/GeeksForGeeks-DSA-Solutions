class Solution {
  public:
    vector<vector<int>> uniqueRow(vector<vector<int>>& mat) {
        // code here
        vector<vector<int>> result;
        result.push_back(mat[0]);
        
        int row = mat.size();
        int col = mat[0].size();
        
        for(int i=1; i<row; i++){
            bool duplicate = false;
            for(int j = 0; j<result.size(); j++){
                
                if(result[j] == mat[i]){
                    duplicate = true;
                    break;
                }
            }
            
            if(!duplicate){
                result.push_back(mat[i]);
            }
        }
        
        return result;
    }
};