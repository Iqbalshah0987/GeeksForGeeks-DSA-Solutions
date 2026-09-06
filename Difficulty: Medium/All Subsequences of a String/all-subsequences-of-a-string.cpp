class Solution {
  public:
    void subsequence(string &s, int index, string curr, vector<string> &ans){
        if(index >= s.size()){
            ans.push_back(curr);
            return;
        }
        
        // don't take current character
        subsequence(s, index+1, curr, ans);
        // take current character
        subsequence(s, index+1, curr+s[index], ans);
    }
    vector<string> powerSet(string &s) {
        // Code here
        vector<string> ans;
        subsequence(s, 0, "", ans);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};