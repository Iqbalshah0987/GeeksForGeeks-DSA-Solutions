class Trie{
    private:
        vector<Trie*> children;
        int freq;
        int data;
        bool isTerminal;

    public:
        Trie(int ch){
            data = ch;
            freq = 0;
            isTerminal = false;
            children = vector<Trie*>(26, NULL);
        }
        
        void insert(string &word){
            Trie *curr = this;

            for(char ch: word){
                if(curr->children[ch-'a'] == NULL){
                    curr->children[ch-'a'] = new Trie(ch);
                }

                curr = curr->children[ch-'a'];
                curr->freq++;
            }
            curr->isTerminal = true;
        }
        
        // Getters
        bool getIsTerminal() {
            return isTerminal;
        }

        Trie* getChild(int index) {
            return children[index];
        }
};
class Solution {
  public:
    void displayUntil(Trie *curr, string prefix, vector<string> &ans){
        
        if(curr->getIsTerminal()){
            ans.push_back(prefix);
        }
        
        for(int i=0; i<26; i++){
            Trie *next = curr->getChild(i);
            
            if(next != NULL){
                displayUntil(next, prefix+char(i+'a'), ans);
            }
        }
    }
    vector<vector<string>> displayContacts(vector<string> &contact, string &s) {
        // code here
        vector<vector<string>> result;
        
        Trie *root = new Trie('\0');
        
        int n = contact.size();
        for(int i=0; i<n; i++){
            root->insert(contact[i]);
        }
        
        Trie *prev = root;
        
        string prefix="";
        int len = s.size();
        int i;
        for(i=0; i<len; i++){
            prefix += s[i];
            
            char lastChar = prefix[i];
            
            Trie *curr = prev->getChild(lastChar-'a');
            
            if(curr == NULL){
                break;
            }
            
            vector<string> ans;
            displayUntil(curr, prefix, ans);
            result.push_back(ans);
            
            prev = curr;
        }
        
        for(; i<len; i++){
            result.push_back({"0"});
        }
        
        return result;
    }
};