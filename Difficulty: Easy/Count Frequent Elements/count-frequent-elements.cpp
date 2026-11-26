class Solution {
  public:
    int countOccurence(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        unordered_map<int, int> freq;
        for(int num: arr){
            freq[num]++;
        }
        
        int count=0;
        for(auto it: freq){
            if(it.second > n/k){
                count++;
            }
        }
        
        return count;
    }
};