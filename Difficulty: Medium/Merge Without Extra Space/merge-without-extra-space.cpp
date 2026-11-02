class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        
        int n1 = a.size();
        int n2 = b.size();
        
        int gap = (n1+n2+1)/2;
        
        while(gap > 0){
            
            int i=0, j=gap;
            while(j < (n1+n2)){
                // when both i and j in array 1
                if(i<n1 && j<n1){
                    if(a[i]>a[j]){
                        swap(a[i], a[j]);
                    }
                }
                // when both i and j in array 2
                else if(i>=n1 && j>=n1){
                    if(b[i-n1]>b[j-n1]){
                        swap(b[i-n1], b[j-n1]);
                    }
                }
                // when i and array 1 and j in array 2
                else{
                    if(a[i] > b[j-n1]){
                        swap(a[i], b[j-n1]);
                    }
                }
                
                i++; j++;
            }
            
            gap = gap==1? 0: (gap+1)/2;
        }
        
    }
};