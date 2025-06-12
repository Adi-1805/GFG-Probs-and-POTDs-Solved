class Solution {
    vector<int> topo;
    bool dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<bool>& pathVis){
        vis[node] = 1; pathVis[node] = 1;
        for(auto next: adj[node]){
            if(!vis[next]){
                if(dfs(next, adj, vis, pathVis) == true) return true; // we found a cycle
            }else{
                if(pathVis[next]) return true;
            }
        }
        pathVis[node] = 0;
        topo.push_back(node);
        return false;
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto& vec: edges){
            adj[vec[1]].push_back(vec[0]); 
        }

        vector<bool> vis(V,0);
        vector<bool> pathVis(V,0);

        for(int i = 0; i < V; i++){
            if(!vis[i]){
                if(dfs(i, adj, vis, pathVis) == true) return {}; // we found a cycle
            }
        }
        return topo;
    }
};