class Solution {
  public:
    int findSubString(string& str) {
        // code here
        int n = str.size();
        unordered_set<char> freq(str.begin(), str.end());
        int totalDistinct = freq.size();
        
        unordered_map<char, int> window;
        int formed=0, index=0, ans=INT_MAX;
        for(int i=0; i<n; i++){
            window[str[i]]++;
            
            if(window[str[i]] == 1){
                formed++;
            }
            
            while(formed == totalDistinct){
                ans = min(ans, i-index+1);
                
                window[str[index]]--;
                if(window[str[index]] == 0){
                    formed--;
                }
                index++;
            }
        }
        
        return ans;
    }
};