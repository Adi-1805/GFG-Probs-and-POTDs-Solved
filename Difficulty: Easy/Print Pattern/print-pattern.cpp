// User function Template for C++

class Solution {
    void solve(int N,vector<int>& ans){
        if(N<=0){
            ans.push_back(N);
            return ;
        }
        
        ans.push_back(N);
        N -= 5;
        solve(N, ans);
        N += 5;
        ans.push_back(N);
    }
  public:
    vector<int> pattern(int N) {
        // code here
        vector<int> ans;
        solve(N, ans);
        return ans;
    }
};