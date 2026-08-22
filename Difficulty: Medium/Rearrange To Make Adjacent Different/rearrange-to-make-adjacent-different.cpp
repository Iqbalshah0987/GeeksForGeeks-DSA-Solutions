class Solution {
  public:
    bool canRearrange(string& s) {
        // code here
        int n = s.length();
        int desired = (n+1)/2;
        
        vector<int> freq(26, 0);
        
        for(char ch: s){
            freq[ch-'a']+=1;
            
            if(freq[ch-'a'] > desired){
                return false;
            }
        }
        
        return true;
    }
};