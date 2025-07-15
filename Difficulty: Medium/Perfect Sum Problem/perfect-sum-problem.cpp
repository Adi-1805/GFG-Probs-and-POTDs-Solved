class Solution {
    vector<vector<int>> dp;
    int solve(vector<int>& arr, int ind, int target){
        if (ind < 0) {
            return target == 0 ? 1 : 0;
        }
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int not_take = solve(arr, ind-1, target);
        int take = 0;
        if(arr[ind] <= target) take = solve(arr, ind-1, target - arr[ind]);
        
        return dp[ind][target] = take + not_take;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        dp.resize(n, vector<int>(target+1, -1));
        return solve(arr, n-1, target);
    }
};