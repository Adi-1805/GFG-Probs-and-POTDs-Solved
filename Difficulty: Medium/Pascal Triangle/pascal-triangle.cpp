
class Solution {
    void solve(int n, vector<vector<int>>& ans){
        if(n == 1){
            return ;
        }
        solve(n-1, ans);
        vector<int> row(n,0);
        row[0] = 1; row[n-1] = 1;
        for(int i = 1; i < n-1; i++){
            row[i] = ans[n-1][i-1] + ans[n-1][i];
        }
        ans.push_back(row);
    }
  public:
    vector<int> nthRowOfPascalTriangle(int n) {
        // code here
        vector<vector<int>> ans;
        if(n == 1) return {1};
        ans.push_back({1});
        ans.push_back({1, 1});
        solve(n, ans);
        return ans[n];
    }
};
