class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &weight) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(W+1, 0));
        for(int wt = 0; wt <= W; wt++){
            if(weight[0] <= wt) dp[0][wt] = val[0];
            else dp[0][wt] = 0;
        }
        for(int ind = 1; ind < n; ind++){
            for(int wt = 0; wt <= W; wt++){
                int not_take = dp[ind-1][wt];
                int take = INT_MIN;
                if(weight[ind] <= wt) take = val[ind] + dp[ind-1][wt - weight[ind]];
                
                dp[ind][wt] = max(not_take, take);
            }
        }
        return dp[n-1][W];
    }
};