class Solution {
  public:
    vector<int> findDuplicates(vector<int>& arr) {
        // code here
        
        vector<int> ans;
        for(int num: arr){
            int idx = abs(num)-1;
            if(arr[idx] < 0){
                ans.push_back(abs(num));
            }else{
                arr[idx] = -arr[idx];
            }
            
        }
        
        return ans;
    }
};