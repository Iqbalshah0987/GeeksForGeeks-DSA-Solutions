class Solution {
  public:
    string countAndSay(int n) {
        // code here
        string curr="1";
        
        for(int i=2; i<=n; i++){
            string next="";
            int cnt=1;
            
            for(int j=1; j<curr.length(); j++){
                if(curr[j-1] == curr[j]){
                    cnt++;
                }else{
                    next += to_string(cnt) + curr[j-1];
                    cnt=1;
                }
            }
            
            next += to_string(cnt) + curr.back();
            curr = next;
        }
        
        return curr;
    }
};