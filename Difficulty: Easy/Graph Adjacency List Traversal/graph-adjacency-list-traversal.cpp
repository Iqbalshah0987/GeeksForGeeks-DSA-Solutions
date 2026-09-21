class Solution {
  public:
    vector<vector<int>> printGraph(int V, vector<pair<int, int>>& edges) {
        // code here
        vector<vector<int>> list(V);
        
        int n = edges.size();
        for(int i=0; i<n; i++){
            int u = edges[i].first;
            int v = edges[i].second;
            
            list[u].push_back(v);
            list[v].push_back(u);
        }
        
        return list;
    }
};