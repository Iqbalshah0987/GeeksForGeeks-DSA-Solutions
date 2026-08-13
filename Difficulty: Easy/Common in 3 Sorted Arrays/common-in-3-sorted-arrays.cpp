class Solution {
  public:
    vector<int> commonElements(vector<int> &a, vector<int> &b, vector<int> &c) {
        // code here
        
        int n1=a.size(), n2=b.size(), n3=c.size();
        int i=0, j=0, k=0;
        
        vector<int> ans;
        
        while(i<n1 && j<n2 && k<n3){
            
            if(a[i]==b[j] && b[j]==c[k]){
                ans.push_back(a[i]);
                i++; j++; k++;
                
                while(i<n1 && a[i-1]==a[i]) i++;
                while(i<n1 && b[j-1]==b[j]) j++;
                while(i<n1 && c[k-1]==c[k]) k++;
                
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