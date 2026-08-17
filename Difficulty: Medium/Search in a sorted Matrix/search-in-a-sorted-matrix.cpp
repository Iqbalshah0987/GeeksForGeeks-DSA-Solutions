class Solution {
  public:
    bool searchMatrix(vector<vector<int>> &mat, int x) {
        // code here
        int row=mat.size(), col=mat[0].size();
        
        int low=0, high=(row*col)-1;
        
        while(low<=high){
            int mid = low + (high-low)/2;
            
            int r = mid/col;
            int c = mid%col;
            
            if(mat[r][c] == x){
                return true;
            }else if(mat[r][c] > x){
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        
        return false;
    }
};