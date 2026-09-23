class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int V = adj.size();
        vector<int> ans;
        vector<bool> visited(V, false);
        
        queue<int> q;
        q.push(0);
        visited[0] = true;
        
        while(!q.empty()){
            int top = q.front();
            q.pop();
            
            ans.push_back(top);
            
            for(int num: adj[top]){
                if(!visited[num]){
                    q.push(num);
                    visited[num] = true;
                }
            }
        }
        
        return ans;
    }
};