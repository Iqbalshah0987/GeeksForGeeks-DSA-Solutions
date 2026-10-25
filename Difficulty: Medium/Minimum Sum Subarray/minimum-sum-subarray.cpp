class Solution {
  public:
    int minSubarraySum(vector<int> &arr) {
        // code here
        
        int sum=INT_MAX, minsum=INT_MAX;
        for(int num: arr){
            sum = min(sum, 0);
            
            sum += num;

            minsum = min(minsum, sum);
        }

        return minsum;
    }
};