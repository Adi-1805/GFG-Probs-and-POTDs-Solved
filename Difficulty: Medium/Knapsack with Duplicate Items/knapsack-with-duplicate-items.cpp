// User function Template for C++

class Solution {
    int solve(int ind, int capacity, vector<int>& val, vector<int>& weight, vector<vector<int>>& dp){
        if(ind == 0){
            if(weight[0] <= capacity) return (capacity/weight[0])*val[0];
            else return 0;
        }
        if(dp[ind][capacity] != -1) return dp[ind][capacity];

        int not_take = solve(ind-1, capacity, val, weight, dp), take = -1e9;
        if(weight[ind] <= capacity) take = val[ind] + solve(ind, capacity - weight[ind], val, weight, dp);
        return dp[ind][capacity] = max(not_take, take);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity+1, -1));
        return solve(n-1, capacity, val, wt, dp);
    }
};