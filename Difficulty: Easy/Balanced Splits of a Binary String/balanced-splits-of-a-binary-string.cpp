class Solution {
  public:
    int maxSubStr(string &s) {
        // code here
        
        int n = s.length();
        int balanced=0, ans=0;
        
        for(int i=0; i<n; i++){
            if(s[i] == '0'){
                balanced++;
            }else{
                balanced--;
            }
            
            if(balanced==0){
                ans++;
            }
        }
        
        return balanced==0? ans: -1;
    }
};
