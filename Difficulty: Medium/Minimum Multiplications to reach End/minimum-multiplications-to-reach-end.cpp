// User function Template for C++
const int M = 1e5;
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        int n = arr.size();
        vector<int> dist(1e5, 1e9);
        dist[start] = 0;
        
        queue<pair<int, int>> q; 
        q.push({start, 0});
        
        while(!q.empty()){
            auto val = q.front().first;
            auto step = q.front().second;
            q.pop();
            for(int i = 0; i < n; i++){
                int num = (arr[i]*val)%M;
                if(step + 1 < dist[num]){
                    dist[num] = step + 1;
                    q.push({num, dist[num]});
                }
            }
        }
        return (dist[end] == 1e9) ? -1 : dist[end];
    }
};
