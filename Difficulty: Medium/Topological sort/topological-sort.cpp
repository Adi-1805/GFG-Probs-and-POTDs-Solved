class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for(auto& vec: edges){
            adj[vec[0]].push_back(vec[1]); 
        }
  
        vector<int> indegree(V,0);
        queue<int> q;
        vector<int> topo;

        for(int i = 0; i < V; i++){
            for(int node: adj[i]){
                indegree[node]++;
            }
        }

        for(int i = 0; i < V; i++){
            if(indegree[i] == 0) q.push(i);
        }

        while(!q.empty()){
            auto node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto next: adj[node]){
                indegree[next]--;
                if(indegree[next] == 0) q.push(next);
            }
        }

        return topo;
    }
};