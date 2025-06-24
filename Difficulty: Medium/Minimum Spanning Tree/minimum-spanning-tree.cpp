class Solution {
  public:
    // Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[]) {
        // code here
        int sum = 0;
        
        vector< pair<int, int>> mst;
        vector<bool> vis(V, 0);
        
        priority_queue< vector<int>, vector<vector<int>>, greater<vector<int>> > pq;
        pq.push({0, 0 , -1}); // {wt, node, parent};
        
        while(!pq.empty()){
            auto wt = pq.top()[0];
            auto node = pq.top()[1];
            auto parent = pq.top()[2];
            pq.pop();
            if(vis[node]) continue;
            vis[node] = 1;
            mst.push_back({parent, node});
            sum += wt;
            for(auto& next: adj[node]){
                auto nbr = next[0];
                auto edgeWt = next[1];
                if(!vis[nbr]){
                    pq.push({edgeWt, nbr, node});
                }
            }
        }
        return sum;
    }
};