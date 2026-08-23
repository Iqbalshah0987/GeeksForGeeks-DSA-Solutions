class Solution {
  public:
    int countMinReversals(string s) {
        // code here
        int n = s.size();
        
        if(n%2 == 1) return -1;
        
        stack<char> st;
        for(char ch: s){
            if(st.empty() || ch=='{' || st.top()=='}'){
                st.push(ch);
            }else{
                st.pop();
            }
        }
        
        int open=0, close=0;
        while(!st.empty()){
            if(st.top()=='{'){
                open++;
            }else{
                close++;
            }
            
            st.pop();
        }
        
        return ceil(open/2.0)+ceil(close/2.0);
    }
};