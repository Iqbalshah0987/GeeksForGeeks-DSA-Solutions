class Solution {
  public:
    int maxSubarraySum(vector<int> &arr) {
        // Code here
        
        int sum=0, maxsum=INT_MIN;
        for(int num: arr){
            sum += num;
            
            maxsum = max(maxsum, sum);
            sum = max(sum, 0);
        }
        
        return maxsum;
    }
};