class Solution {
  public:
    bool isPalindrome(int n){
        int num = n;
        int rev = 0;
        while(num!=0){
            int rem = num%10;
            rev = rev*10 + rem;
            num /= 10;
        }
        
        return rev==n;
    }
    bool isPalinArray(vector<int> &arr) {
        // code here
        
        int n = arr.size();
        for(int i=0; i<n; i++){
            if(!isPalindrome(arr[i])){
                return false;
            }
        }
        
        return true;
    }
};