class Solution {
  public:
    vector<int> spirallyTraverse(vector<vector<int>> &mat) {
        // code here
        int row=mat.size(), col=mat[0].size();
        vector<int> ans;
        
        int left=0, right=col-1, top=0, bottom=row-1;
        while(left<=right && top<=bottom){
            
            // left to right
            for(int i=left; i<=right; i++){
                ans.push_back(mat[top][i]);
            }
            top++;
            
            // top to bottom
            for(int i=top; i<=bottom; i++){
                ans.push_back(mat[i][right]);
            }
            right--;
            
            if(top<=bottom){
                // right to left
                for(int i=right; i>=left; i--){
                    ans.push_back(mat[bottom][i]);
                }
                bottom--;
            }
            
            if(left<=right){
                // bottom to top
                for(int i=bottom; i>=top; i--){
                    ans.push_back(mat[i][left]);
                }
                left++;
            }
        }
        
        return ans;
    }
};