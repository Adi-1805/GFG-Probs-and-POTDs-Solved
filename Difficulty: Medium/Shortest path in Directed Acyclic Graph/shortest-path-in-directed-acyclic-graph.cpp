// User function Template for C++
class Solution {
    void dfs(int node, vector<vector<pair<int, int>>>& adj, vector<bool>& vis, stack<int>& st){
        vis[node] = 1; 
        for(auto& pair: adj[node]){
            int next = pair.first;
            if(!vis[next]) dfs(next, adj, vis, st);
        }
        st.push(node);
    }
    
  public:
    vector<int> shortestPath(int V, int E, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int, int>>> adj(V);
        for(int i = 0; i < E; i++){
            for(auto& vec: edges){
                adj[vec[0]].push_back({vec[1], vec[2]});
            }
        }
        
        vector<bool> vis(V, 0);
        stack<int> st;
        for(int node = 0; node < V; node++){
            if(!vis[node]) dfs(node, adj, vis, st);
        }
        
        vector<int> dist(V, 1e9);
        dist[0] = 0;
        
        while(!st.empty()){
            auto node = st.top(); st.pop();
            for(auto& pair: adj[node]){
                int next = pair.first;
                int wt = pair.second;
                if(dist[node] + wt < dist[next]){
                    dist[next] = dist[node] + wt;
                }
            }
        }
        
        for(auto& val:dist){
            if(val == 1e9) val = -1;
        }
        return dist;
        
    }
};
