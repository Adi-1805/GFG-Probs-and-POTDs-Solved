class Solution {
  public:
    // Function to find the shortest path from source to all other nodes
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        // code here
        int V = adj.size();
        bool vis[V] = {0};
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        
        queue<int> q;
        q.push(src);
        vis[src] = 1;
        
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            for(auto next: adj[node]){
                if(!vis[next]){
                    q.push(next); dist[next] = dist[node] +1;
                    vis[next] = 1;
                }
            }
        }
        
        for(auto& val:dist){
            if(val == 1e9) val = -1;
        }
        
        return dist;
    }
};