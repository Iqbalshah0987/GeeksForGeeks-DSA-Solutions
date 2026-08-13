class Solution {
  public:
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        priority_queue<int> maxheap;
        
        for(int num: arr){
            maxheap.push(num);
            
            if(maxheap.size() > k){
                maxheap.pop();
            }
        }
        
        return maxheap.top();
    }
};