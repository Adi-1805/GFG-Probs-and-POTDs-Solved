class Solution {
    bool dfs(int node, vector<vector<int>> &adj, vector<int> &vis, int curColor){
        vis[node] = curColor;
        
        for(auto next: adj[node]){
            if(vis[next] == -1){
                if(dfs(next, adj, vis, !curColor) == 0) return false;
            } 
            else{
                if(vis[node] == vis[next]) return false;
            }
        }
        return true;
    }
  public:
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<vector<int>> adjList(V);
        for(auto& vec: edges){
            adjList[vec[0]].push_back(vec[1]);
            adjList[vec[1]].push_back(vec[0]);
        }
        
        vector<int> vis(V, -1);
        
        for(int i = 0; i < V; i++){
            if(vis[i] == -1) {
                if( dfs(i, adjList, vis, 0) == 0) return false; 
            }
        }
            
        return true;
    }
};