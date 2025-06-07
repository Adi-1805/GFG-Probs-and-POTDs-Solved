class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        vector<int> ans;
        queue<int> q; q.push(0); 
        vector<bool> vis(adj.size()+1,0); vis[0] = 1;
        while(!q.empty()){
            auto node = q.front(); q.pop();
            ans.push_back(node);
            for(int next: adj[node]){
                if(!vis[next]){
                    q.push(next); vis[next] = 1;
                }
            }
        }
        return ans;
    }
};