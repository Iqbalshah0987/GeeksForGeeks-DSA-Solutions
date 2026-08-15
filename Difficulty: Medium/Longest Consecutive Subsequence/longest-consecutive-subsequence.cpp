class Solution {
  public:
    int longestConsecutive(vector<int>& arr) {
        // code here
        unordered_set<int> st(arr.begin(), arr.end());
        int ans=INT_MIN;
        
        for(int num: arr){
            
            if(st.find(num)!=st.end() && st.find(num-1)==st.end()){
                
                int cnt=0, curr=num;
                while(st.find(curr)!=st.end()){
                    cnt++;
                    curr++;
                }
                
                ans = max(ans, cnt);
            }
        }
        
        return ans;
    }
};