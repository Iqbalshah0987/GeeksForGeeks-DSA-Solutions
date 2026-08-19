class Solution {
  public:
    int romanToInteger(string &s) {
        // code here
        unordered_map<char, int> mp = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        
        int n = s.size()-1, ans=0;
        
        for(int i=n; i>=0; i--){
            if(i<n && mp[s[i]] < mp[s[i+1]]){
                ans -= mp[s[i]];
            }else{
                ans += mp[s[i]];
            }
        }
        
        return ans;
    }
};