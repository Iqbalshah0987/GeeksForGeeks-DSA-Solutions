class Solution {
  public:
    int kthLargest(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        vector<int> sumStore;
        
        for(int i=0; i<n; i++){
            int sum=0;
            for(int j=i; j<n; j++){
                sum += arr[j];
                sumStore.push_back(sum);
            }
        }
        
        sort(sumStore.begin(), sumStore.end());
        
        int size = sumStore.size();
        
        return sumStore[size-k];
    }
};