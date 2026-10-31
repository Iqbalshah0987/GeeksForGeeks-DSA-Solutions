class Solution {
  public:
    string chooseSwap(string &s) {
        // code here
        
        int n = s.length();
        
        
        // fina all characters first occurences
        vector<int> first(26, -1);
        for(int i=0; i<n; i++){
            int ch = s[i]-'a';
            
            if(first[ch] == -1){
                first[ch] = i;
            }
        }
        
        
        
        // traverse from left to right and find, leftmost character which is greater than rightmost character
        char x=0, y=0; 
        int pos=-1;
        for(int i=0; i<n; i++){
            
            int curr = s[i]-'a';
            for(int c=0; c<curr; c++){
                
                if(first[c] > i){
                    pos = i;
                    x = s[i];
                    y = char('a'+c);
                    break;
                }
            }
            
            if(pos != -1) break;
        }
        
        // if any character not found that means current string is lexicographically smallest
        if(pos == -1){
            return s;
        }
        
        string res = s;
        for(char &ch: res){
            if(ch == x){
                ch = y;
            }else if(ch == y){
                ch = x;
            }
        }
        
        return res;
    }
};
