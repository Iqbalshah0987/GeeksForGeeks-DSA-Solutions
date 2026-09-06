class Solution {
  public:
    void solve(string &s, int index, vector<string> &ans){
        if(index >= s.size()){
            ans.push_back(s);
            return;
        }
        
        unordered_set<char> used;
        for(int i=index; i<s.size(); i++){
            
            if(used.count(s[i])) continue;
            used.insert(s[i]);
        
            swap(s[index], s[i]);
            solve(s, index+1, ans);
            
            // backtrach
            swap(s[index], s[i]);
        }
    }
    vector<string> findPermutation(string &s) {
        // Code here
        
        vector<string> ans;
        solve(s, 0, ans);
        return ans;
    }
};
