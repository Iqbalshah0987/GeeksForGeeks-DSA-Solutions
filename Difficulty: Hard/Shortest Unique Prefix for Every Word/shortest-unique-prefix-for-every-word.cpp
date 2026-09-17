class Trie{
    private:
        vector<Trie*> children;
        int freq;
        int data;
        
    public:
        Trie(int ch){
            data = ch;
            freq = 0;
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
        }
        
        int prefix(string &word){
            Trie *curr = this;
            
            for(int i=0; i<word.length(); i++){
                curr = curr->children[word[i]-'a']; 
                
                if(curr->freq == 1){
                    return i;
                }
            }
            
            return word.size()-1;
        }
        
        void deleteTrie(Trie *root){
            if(root==NULL) return;
            
            for(int i=0; i<26; i++){
                deleteTrie(root->children[i]);
                delete root->children[i];
            }
        }
};

class Solution {
  public:
    vector<string> findPrefixes(vector<string>& arr) {
        // code here
        Trie *root = new Trie('\0');
        
        int n = arr.size();
        for(int i=0; i<n; i++){
            root->insert(arr[i]);
        }
        
        
        vector<string> result;
        for(int i=0; i<n; i++){
            string word = arr[i];
            
            int endIndex = root->prefix(word);
            
            result.push_back(word.substr(0, endIndex+1));
        }
        
        root->deleteTrie(root);
        
        return result;
    }
};