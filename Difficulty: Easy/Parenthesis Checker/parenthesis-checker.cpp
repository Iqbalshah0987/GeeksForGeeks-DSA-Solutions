class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char> st;
        
        for(char ch: s){
            
            if(!st.empty() && (
                (ch==')' && st.top()=='(') ||
                (ch=='}' && st.top()=='{') ||
                (ch==']' && st.top()=='[')
            )){
                st.pop();
            }else{
                st.push(ch);
            }
        }
        
        return st.size()==0;
    }
};