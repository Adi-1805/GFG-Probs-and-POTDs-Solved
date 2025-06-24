// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        
        for(int i = 0; i < V; i++){
            for(auto vec: edges){
                int u = vec[0];
                int v = vec[1];
                int wt = vec[2];
                if(dist[u] != 1e8 and dist[u] + wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        for(int i = 0; i < V; i++){
            for(auto vec: edges){
                int u = vec[0];
                int v = vec[1];
                int wt = vec[2];
                if(dist[u] != 1e8 and dist[u] + wt < dist[v]){
                    return {-1};
                }
            }
        }
        return dist;
    }
};
