class Solution {
  public:
    int minJumps(vector<int>& arr) {
        // code here
        
        if(arr[0] == 0) return -1;
        
        int n = arr.size();
        int jumps=1, steps=arr[0], maxi=arr[0];
        
        for(int i=1; i<n; i++){
            
            steps--;
            maxi = max(maxi-1, arr[i]);
            
            if(steps==0 && i<n-1){
                if(arr[i]==0 && maxi==0) return -1;
                
                jumps++;
                steps = maxi;
            }
        }
        
        return jumps;
    }
};
