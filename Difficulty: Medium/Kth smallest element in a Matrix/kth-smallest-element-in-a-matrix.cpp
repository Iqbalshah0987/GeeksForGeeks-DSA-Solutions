class Solution {
  public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        // code here
        int row=mat.size(), col=mat[0].size();
        
        int mini = mat[0][0];
        int maxi = mat[row-1][col-1];
        
        while(mini < maxi){
            
            int mid = (mini+maxi)/2;
            
            int place=0;
            for(int i=0; i<row; i++){
                place += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            
            if(place < k){
                mini = mid+1;
            }else{
                maxi = mid;
            }
        }
        
        return mini;
    }
};
