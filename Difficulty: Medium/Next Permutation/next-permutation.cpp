class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        
        // step 1: find a number from `right to left` which is smaller than the right value
        int i=arr.size()-2;
        while(i>=0 && arr[i]>=arr[i+1]) i--;
        
        // step 2: find a number from `right to left` which is greater than the ith value
        if(i>=0){
            int j=arr.size()-1;
            while(j>=i && arr[j] <= arr[i]) j--;
            
            swap(arr[i], arr[j]);
        }
        
        // step 3: reverse from ith to end of the array
        reverse(arr.begin()+i+1, arr.end());
    }
};