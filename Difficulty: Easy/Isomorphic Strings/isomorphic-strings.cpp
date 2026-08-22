class Solution {
  public:
    bool areIsomorphic(string &s1, string &s2) {
        // code here
        
        if(s1.length() > s2.length()){
            return areIsomorphic(s2, s1);
        }
        
        unordered_map<char, char> mp1, mp2;
        for(int i=0; i<s1.size(); i++){
            
            if(mp1.find(s1[i])!=mp1.end() && mp1[s1[i]]!=s2[i]){
                return false;
            }
            
            if(mp2.find(s2[i])!=mp2.end() && mp2[s2[i]]!=s1[i]){
                return false;
            }
            
            mp1[s1[i]] = s2[i];
            mp2[s2[i]] = s1[i];
        }
        
        return true;
    }
};