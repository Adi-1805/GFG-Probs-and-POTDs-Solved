// User function Template for C++

class Solution {
    void solve(int N, int A, int C, int B, vector<pair<int, int>>& steps){
        if(N==1){
            steps.push_back({A,C});
            return ;
        }
        
        solve(N-1, A, B, C, steps);
        steps.push_back({A,C});
        solve(N-1, B, C, A, steps);
    }
  public:
    vector<int> shiftPile(int N, int n) {
        // code here
        int src = 1, dest = 3, help = 2;
        // Need to move from src to dest using help
        vector<pair<int, int>> steps;
        
        solve(N, src, dest, help, steps);
        return {steps[n-1].first, steps[n-1].second};
        
        
    }
};