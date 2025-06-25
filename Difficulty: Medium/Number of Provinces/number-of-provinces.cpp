// User function Template for C++
class DisjointSet {
    vector<int> parent, size, rank;
    public:
    DisjointSet(int n) {
        rank.resize(n+1, 0); size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i < n; i++) parent[i] = i;
    }
    int findUltPar(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUltPar(parent[node]);
    }
    void unionBySize(int u, int v){
        int pu = findUltPar(u);
        int pv = findUltPar(v);
        if(pu == pv) return;
        // Compare size of parents
        if(size[pu] > size[pv]){ 
            parent[pv] = pu;
            size[pu] += size[pv];
        } else { 
            parent[pu] = pv;
            size[pv] += size[pu];
        }
    }
    void unionByRank(int u, int v){
        int pu = findUltPar(u);
        int pv = findUltPar(v);
        if(pu == pv) return;
        // Compare size of parents
        if(rank[pu] > rank[pv]){ 
            parent[pv] = pu;
        } else if(rank[pu] < rank[pv]) { 
            parent[pu] = pv;
        } else {
            parent[pu] = pv;
            rank[pv] += 1;
        }
    }
    
};

class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        // code here
        int m = adj.size(), n = adj[0].size();
        DisjointSet ds(V);
        // vector<pair<int, int>> edges;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(adj[i][j]){
                    // edges.push_back({i , j});
                    ds.unionBySize(i, j);
                }
            }
        }
        int ans = 0;
        for(int i = 0; i < V; i++){
            if(ds.findUltPar(i) == i) ans++;
        }
        return ans;
    }
};