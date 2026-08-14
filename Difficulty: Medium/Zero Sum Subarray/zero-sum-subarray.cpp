class Solution {
  public:
    bool subArrayExists(vector<int>& arr) {
        // code here
        
        unordered_set<int> st;
        int sum=0;
        for(int num: arr){
            sum += num;
            
            if(sum==0 || st.find(sum)!=st.end()){
                return true;
            }
            
            st.insert(sum);
        }
        
        return false;
    }
};