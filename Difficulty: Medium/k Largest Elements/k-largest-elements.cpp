class Solution {
  public:
    vector<int> kLargest(vector<int>& arr, int k) {
        // code here
        priority_queue<int> pq;
        
        for(int num: arr){
            pq.push(num);
        }
        
        vector<int> ans;
        while(!pq.empty() && k>0){
            ans.push_back(pq.top());
            pq.pop();
            k--;
        }
        
        return ans;
    }
};