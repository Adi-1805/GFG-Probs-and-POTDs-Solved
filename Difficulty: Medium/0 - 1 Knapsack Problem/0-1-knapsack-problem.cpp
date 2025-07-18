class Solution {
    vector<vector<int>> dp;
    int solve(int ind, int wt, vector<int> &arr, vector<int> &weight){
        if(ind == 0){
            if(weight[ind] <= wt) return arr[ind];
            else return 0;
        }
        if(dp[ind][wt] != -1) return dp[ind][wt];
        
        int not_take = solve(ind-1, wt, arr, weight);
        int take = INT_MIN;
        if(weight[ind] <= wt) take = arr[ind] + solve(ind-1, wt - weight[ind], arr, weight);
        return dp[ind][wt] = max(not_take, take);
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        dp.resize(n, vector<int>(W+1, -1));
        return solve(n-1, W, val, wt);
    }
};