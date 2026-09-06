class Solution {
  public:
    string minWindow(string &s, string &p) {
        // code here
        unordered_map<char, int> need;
        for(char ch: p){
            need[ch]++;
        }

        int n = s.size(), matched=0, index=0, minLen=INT_MAX, start=0;
        unordered_map<char, int> window;
        for(int i=0; i<n; i++){
            char ch = s[i];
            window[ch]++;

            if(need.count(ch) && window[ch]<=need[ch]){
                matched++;
            }

            while(matched == p.size()){
                if(i-index+1 < minLen){
                    minLen = i-index+1;
                    start = index;
                }
                char ch = s[index];
                window[ch]--;

                if(need.count(ch) && window[ch]<need[ch]){
                    matched--;
                }
                index++;
            }
        }

        return minLen==INT_MAX? "": s.substr(start, minLen);
    }
};