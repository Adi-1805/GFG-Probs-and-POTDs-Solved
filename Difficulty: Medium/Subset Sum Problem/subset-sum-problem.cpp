class Solution {
    vector<vector<int>> dp;
    bool solve(int ind, int n, vector<int>& arr, int cursum, int sum){
        if(sum == cursum) return 1;
        if(ind == n || cursum > sum) return 0;
        if(dp[ind][cursum] != -1) return dp[ind][cursum];
        
        //pick
        bool pick = solve(ind+1, n, arr, cursum + arr[ind], sum);
        // un-pick
        bool notpick = solve(ind+1, n, arr, cursum, sum);
        
        return dp[ind][cursum] = (pick || notpick);
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        if (n == 0) return sum == 0;
        
        int total = accumulate(arr.begin(), arr.end(), 0);
        if(total < sum) return 0;
        
        // dp has two states: ind and cursum
        dp.resize(n, vector<int>(total+1, -1));
        return solve(0, n, arr, 0, sum);
    }
};