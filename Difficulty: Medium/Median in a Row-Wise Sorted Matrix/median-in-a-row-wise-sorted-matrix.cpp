class Solution {
  public:
    int median(vector<vector<int>> &mat) {
        // code here
        int row=mat.size(), col=mat[0].size();
        int mini=INT_MAX, maxi=INT_MIN;
        
        for(int i=0; i<row; i++){
            mini = min(mini, mat[i][0]);
            maxi = max(maxi, mat[i][col-1]);
        }
        
        int desired = (row*col+1)/2;
        
        while(mini < maxi){
            int mid = (mini+maxi)/2;
            
            int place=0;
            for(int i=0; i<row; i++){
                place += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
            }
            
            if(place < desired){
                mini = mid+1;
            }else{
                maxi = mid;
            }
        }
        
        return mini;
    }
};
