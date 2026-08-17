class Solution {
  public:
    vector<int> nextSmaller(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n, n);
        stack<int> st;
        
        for(int i=n-1; i>=0; i--){
            
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                ans[i] = st.top();
            }
            
            st.push(i);
        }
        
        return ans;
    }
    vector<int> prevSmaller(vector<int> &arr){
        int n = arr.size();
        vector<int> ans(n, -1);
        stack<int> st;
        
        for(int i=0; i<n; i++){
            
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            
            if(!st.empty()){
                ans[i] = st.top();
            }
            
            st.push(i);
        }
        
        return ans;
    }
    int largestArea(vector<int> &heights){
        int n = heights.size();
        vector<int> next=nextSmaller(heights), prev=prevSmaller(heights);
        int area = INT_MIN;
        
        for(int i=0; i<n; i++){
            int l = heights[i];
            int b = next[i] - prev[i] - 1;
            
            area = max(area, l*b);
        }
        
        return area;
    }
    int maxArea(vector<vector<int>> &mat) {
        // code here
        int row=mat.size(), col=mat[0].size();
        vector<int> heights(col, 0);
        int area = INT_MIN;
        
        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(mat[i][j] == 1){
                    heights[j] += 1;
                }else{
                    heights[j] = 0;
                }
            }
            
            area = max(area, largestArea(heights));
        }
        
        return area;
    }
};