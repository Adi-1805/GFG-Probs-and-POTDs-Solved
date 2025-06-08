class Solution {
    vector<vector<int>> convert(int V, vector<vector<int>>& edges){
        vector<vector<int>> adj(V);
        for(int i = 0; i < edges.size(); i++){
            int v1 = edges[i][0];
            int v2 = edges[i][1];
            
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        return adj;
    }
    
  public:
    bool detect(int node, int parent, const vector<vector<int>>& adj, vector<bool>& vis){
        vis[node] = 1;
        for(auto next : adj[node]) {
            if(!vis[next]) {
                if(detect(next, node, adj, vis)) return true;
            }
            else if(next != parent) {
                return true;
            }
        }
        return false;  
    }
    
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<vector<int>> adj = convert(V, edges); // to convert
        vector<bool> vis(V, 0);
        for(int i = 0; i < V; i++) {  // handle disconnected graphs
            if(!vis[i]) {
                if(detect(i, -1, adj, vis)) return true;
            }
        }
        return false;
    }
};