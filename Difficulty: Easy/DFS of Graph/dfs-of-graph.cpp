class Solution {
  public:
    void dfs(vector<vector<int>>& adj, int node, vector<bool> &visited, vector<int> &ans){
        
        ans.push_back(node);
        visited[node] = true;
        
        for(int num: adj[node]){
            if(!visited[num]){
                dfs(adj, num, visited, ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int V = adj.size();
        vector<bool> visited(V, false);
        vector<int> ans;
        
        dfs(adj, 0, visited, ans);
        
        return ans;
    }
};