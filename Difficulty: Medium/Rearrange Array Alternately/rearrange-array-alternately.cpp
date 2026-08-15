class Solution {
  public:
    void rearrange(vector<int>& arr) {
        // Your code here
        
        sort(arr.begin(), arr.end());
        
        int n = arr.size();
        int maxele = arr[n-1]+1;
        int minidx=0, maxidx=n-1;
        
        for(int i=0; i<n; i++){
            if(i%2 == 0){
                arr[i] += (arr[maxidx]%maxele) * maxele;
                maxidx--;
            }else{
                arr[i] += (arr[minidx]%maxele) * maxele;
                minidx++;
            }
        }
        
        for(int i=0; i<n; i++){
            arr[i] /= maxele;
        }
    }
};