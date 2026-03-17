// User function Template for C++

class Solution {
    void dfs(int node, vector<vector<int>> &adj, vector<int> &vis){
        vis[node] = 1;
        for(int nbr : adj[node]){
            if(!vis[nbr]) dfs(nbr, adj, vis);
        }
    }
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        vector<vector<int>> graph(V);
        for(int i = 0; i < adj.size(); i++){
            for(int j = 0; j < adj[0].size(); j++){
                if(adj[i][j] == 1){
                    graph[i].push_back(j);
                    graph[j].push_back(i);
                }
            }
        }
        
        vector<int> vis(V, 0);
        int components = 0;
        for(int i = 0; i < V; i++){
            if(!vis[i]){
                dfs(i, graph, vis);
                components++;
            } 
        }
        return components;
    }
};