// User function Template for C++
#define ll long long int
const int M = 1e9+7;
class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        // code here
        vector<vector<pair<ll, ll>>> adj(n);
        for(auto& vec:roads){
            adj[vec[0]].push_back({vec[1], vec[2]});
            adj[vec[1]].push_back({vec[0], vec[2]});
        }
        
        vector<ll> time(n, LLONG_MAX);
        time[0] = 0;
        
        vector<ll> ways(n, 0);
        ways[0] = 1;
        
        priority_queue< pair<ll, ll> , vector< pair<ll, ll>>, greater< pair<ll, ll>>> pq; 
        pq.push({0, 0}); // {time, node}
        
        while(!pq.empty()){
            ll node = pq.top().second;
            ll curTime = pq.top().first;
            pq.pop();
            for(auto& next: adj[node]){
                ll nbr = next.first;
                ll edgeWt = next.second;
                if(curTime + edgeWt < time[nbr]){
                    time[nbr] = curTime + edgeWt;
                    pq.push({time[nbr], nbr});
                    ways[nbr] = ways[node]%M;
                }
                else if(curTime + edgeWt == time[nbr]){
                    ways[nbr] = (ways[nbr] + ways[node])%M;
                }
            }
        }
        return ways[n-1]%M;
    }
};