class Solution {
  public:
    bool isSubset(vector<int> &a, vector<int> &b) {
        // code here
        unordered_map<int, int> freq;
        
        for(int num: a){
            freq[num]++;
        }
        
        for(int num: b){
            if(freq.find(num)==freq.end() || freq[num]==0){
                return false;
            }
            freq[num]--;
        }
        
        return true;
    }
};