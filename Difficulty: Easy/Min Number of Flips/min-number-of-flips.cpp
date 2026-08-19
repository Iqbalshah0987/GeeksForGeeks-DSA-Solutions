class Solution {
  public:
    int flipWithStart(string &s, char desired){
        int flip=0;
        
        for(int i=0; i<s.length(); i++){
            if(s[i] == desired){
                flip++;
            }
            
            desired = desired=='0'? '1': '0';
        }
        
        return flip;
    }
    int minFlips(string& s) {
        // code here
        return min(flipWithStart(s, '0'), flipWithStart(s, '1'));
    }
};
