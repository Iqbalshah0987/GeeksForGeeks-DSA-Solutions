class Solution {
  public:
    int rowWithMax1s(vector<vector<int>> &arr) {
        // code here
        
        int row=arr.size(), col=arr[0].size();
        
        int r=0, c=col-1, index=-1;
        while(r<row && c<col){
            if(arr[r][c]==0){
                r++;
            }else{
                c--;
                index = r;
            }
        }
        
        return index;
    }
};