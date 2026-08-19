class Solution {
  public:
    string longestCommonPrefix(vector<string> arr) {
        // your code here
        int n = arr.size();
        string str=arr[0];
        for(int i=1; i<n; i++){
            if(arr[i].length() < str.length()){
                str = arr[i];
            }
        }
        
        string res="";
        bool matched=true;
        for(int i=0; i<str.length(); i++){
            for(int j=0; j<n; j++){
                if(str[i] != arr[j][i]){
                    matched=false;
                    break;
                }
            }
            
            if(!matched) break;
            
            res += str[i];
        }
        
        return res;
    }
};