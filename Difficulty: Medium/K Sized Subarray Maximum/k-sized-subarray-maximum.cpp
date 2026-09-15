class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        // code here
        vector<int> res;
        deque<int> dq(k);
        
        for(int i=0; i<k; i++){
            
            // remvoe all smaller than the crrent being added element
            while(!dq.empty() && arr[i] >= arr[dq.back()] ){
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        for(int i=k; i<arr.size(); i++){
            res.push_back(arr[dq.front()]);
            
            // remove element which are out of this window
            while(!dq.empty() && dq.front() <= i-k ){
                dq.pop_front();
            }
            
            // remvoe all smaller than the crrent being added element
            while(!dq.empty() && arr[i] >= arr[dq.back()] ){
                dq.pop_back();
            }
            
            dq.push_back(i);
        }
        
        res.push_back(arr[dq.front()]);
        
        return res;
    }
};