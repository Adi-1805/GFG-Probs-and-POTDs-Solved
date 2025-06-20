// User Function Template
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int, int>>> adj(V);
        int E = edges.size();
        for(auto& vec:edges){
            adj[vec[0]].push_back({vec[1], vec[2]});
        }
        
        priority_queue< pair<int,int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        vector<int> dist(V, 1e9);
        dist[src] = 0;
        pq.push({0, src});
        
        while(!pq.empty()){
            auto curDist = pq.top().first;
            auto node = pq.top().second;
            pq.pop();
            for(auto& next: adj[node]){
                int nbr = next.first;
                int d = next.second;
                if(curDist + d < dist[nbr]){
                    dist[nbr] = curDist + d;
                    pq.push({dist[nbr], nbr});
                }
            }
        }
        return dist;
    }
};