class Solution {
  public:
    string removeDuplicates(string& s) {
        // code here.
        
        string str="";
        for(char ch: s){
            if(str.back()!=ch){
                str.push_back(ch);
            }
        }
        
        return str;
    }
};