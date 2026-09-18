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
    bool wordBreak(string &s, vector<string> &dictionary) {
        // code here
        Trie *root = new Trie('\0');
        
        int n = dictionary.size();
        for(int i=0; i<n; i++){
            root->insert(dictionary[i]);
        }
        
        
        int size=s.size();
        vector<int> dp(size+1, false);
        dp[0] = true;
        
        for(int i=0; i<size; i++){
            
            if(!dp[i]){
                continue;
            }
            
            Trie *curr = root;
            
            for(int j=i; j<size; j++){
                int index = s[j]-'a';
                
                if(curr->getChild(index) == NULL){
                    break;
                }
                
                curr = curr->getChild(index);
                
                if(curr->getIsTerminal()){
                    dp[j+1] = true;
                }
            }
        }
        
        return dp[size];
    }
};