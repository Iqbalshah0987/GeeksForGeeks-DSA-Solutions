class Solution {
  public:
    vector<vector<int>> getPairs(vector<int>& arr) {
        // code here
        sort(arr.begin(), arr.end());
        
        vector<vector<int>> ans;
        
        int n = arr.size();
        int left=0, right=n-1;
        while(left < right){
            int sum = arr[left]+arr[right];
            
            if(sum == 0){
                ans.push_back({arr[left++], arr[right--]});
                
                while(left < right && arr[left-1]==arr[left]) left++;
                while(left < right && arr[right]==arr[right+1]) right--;
            }else if(sum < 0){
                left++;
            }else{
                right--;
            }
        }
        
        return ans;
    }
};
