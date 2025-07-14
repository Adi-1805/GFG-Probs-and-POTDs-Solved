class Solution {
    vector<vector<int>> dp;
    bool solve(int ind, vector<int>& arr, int sum){
        if(sum == 0) return 1;
        if(ind == 0) return (sum == arr[0]);
        if(dp[ind][sum] != -1) return dp[ind][sum];
        
        // un-pick
        bool notpick = solve(ind-1, arr, sum);
        //pick
        bool pick = 0;
        if(sum >= arr[ind]) pick = solve(ind-1, arr, sum - arr[ind]);
    
        return dp[ind][sum] = (pick || notpick);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        if (n == 0) return sum == 0;
        // dp has two states: ind and cursum
        dp.resize(n, vector<int>(sum+1, -1)); // sum+1 because sum == 0 ki bhi ek state hogi
        return solve(n-1, arr, sum);
    }
};