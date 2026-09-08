class Solution {
  public:
    void inorder(vector<int> &arr, vector<int> &inorderArr, int index){
        if(index >= arr.size()) return;
        
        inorder(arr, inorderArr, 2*index+1);
        inorderArr.push_back(arr[index]);
        inorder(arr, inorderArr, 2*index+2);
    }
    int minSwaps(vector<int>& arr) {
        // your code 
        
        int n = arr.size();
        vector<int> inorderArr;
        
        inorder(arr, inorderArr, 0);
        
        vector<pair<int, int>> t;
        for(int i=0; i<n; i++){
            t.push_back({inorderArr[i], i});
        }
        
        sort(t.begin(), t.end());
        
        int ans=0;
        for(int i=0; i<n; i++){
            
            if(i == t[i].second) continue;
            
            swap(t[i], t[t[i].second]);
            
            if(i != t[i].second){
                i--;
            }
            
            ans++;
        }
        
        return ans;
    }
};


// 8:0 6:1 9:2 5:3 10:4 7:5 11:6

// 5:3 6:1 7:5 8:0 9:2 10:4 11:6