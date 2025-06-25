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
    
};
class Solution {
  public:
    int kruskalsMST(int V, vector<vector<int>> &edges) {
        // code here
        for(auto& vec: edges){
            // Getting the edgeList in the format {edgeWt, u, v} so that we can sort on the basis of edgeWt later
            int temp = vec[2]; // wt
            vec[2] = vec[1];
            vec[1] = vec[0];
            vec[0] = temp;
        }
        sort(edges.begin(), edges.end());
        
        int mstWt = 0;
        DisjointSet ds(V);
        for(auto vec: edges){
            int wt = vec[0];
            int u = vec[1];
            int v = vec[2];
            if(ds.findUltPar(u) != ds.findUltPar(v)){
                mstWt += wt;
                ds.unionBySize(u, v);
            }
        }
        return mstWt;
    }
};