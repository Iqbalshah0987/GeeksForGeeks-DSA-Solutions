class Solution {
  public:
    string getHash(string str){
        
        vector<int> freq(26, 0);
        for(char ch: str){
            freq[ch-'a'] +=1;
        }
        
        string hash="";
        for(int num: freq){
            hash += to_string(num)+"#";
        }
        
        return hash;
    }
    vector<vector<string>> anagrams(vector<string>& arr) {
        // code here
        
        unordered_map<string, vector<string>> mp;
        for(string str: arr){
            string s = getHash(str);
            mp[s].push_back(str);
        }
        
        vector<vector<string>> ans;
        for(auto it: mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};