class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        
        vector<int> ans;
        
        int i=0, j=0, k=0;
        while(i<a.size() && j<b.size() && k<c.size()){
            
            if(a[i]==b[j] && b[j]==c[k]){
                ans.push_back(a[i]);
                i++;
                j++;
                k++;
                
                while(i<a.size() && a[i-1]==a[i]) i++;
                while(j<b.size() && b[j-1]==b[j]) j++;
                while(k<c.size() && c[k-1]==c[k]) k++;
                
            }else if(a[i] < b[j]){
                i++;
            }else if(b[j] < c[k]){
                j++;
            }else{
                k++;
            }
        }
        
        return ans;
    }
};