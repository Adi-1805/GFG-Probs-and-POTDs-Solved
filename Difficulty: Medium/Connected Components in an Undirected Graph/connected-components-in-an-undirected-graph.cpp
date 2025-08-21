
class Solution {
    void dfs(int node, vector<vector<int>>& adj, vector<int>& vis, vector<int>& component){
        vis[node] = 1;
        component.push_back(node);
        for(int next: adj[node]){
            if(!vis[next]){
                dfs(next, adj, vis, component);
            }
        }
    }
  public:
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adjList(V);
        for(auto& vec: edges){
            int u = vec[0], v = vec[1];
            adjList[u].push_back(v);
            adjList[v].push_back(u);
        }
            
        vector<int> visited(V, 0);
        vector<vector<int>> result;
        for(int i = 0; i < V; i++){
            if(!visited[i]){
                vector<int> component;
                dfs(i, adjList, visited, component);
                result.push_back(component);
            }
            
        }
        return result;
            
    }
};
