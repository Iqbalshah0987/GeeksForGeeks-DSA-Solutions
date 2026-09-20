class Solution {
  public:
    bool isPalindrome(string& s) {
        int i = 0, j = s.size() - 1;
        while (i < j) {
            if (s[i++] != s[j--]) 
                return false;
        }
        return true;
    }
    void solve(string &s, int index, vector<string> &curr, vector<vector<string>> &ans){
        if(index >= s.size()){
            ans.push_back(curr);
            return;
        }
        
        string temp="";
        for(int i=index; i<s.size(); i++){
            temp += s[i];
            
            if(isPalindrome(temp)){
                curr.push_back(temp);
                
                solve(s, i+1, curr, ans);
                
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> palinParts(string &s) {
        // code here
        vector<vector<string>> ans;
        vector<string> curr;
        
        solve(s, 0, curr, ans);
        
        return ans;
    }
};