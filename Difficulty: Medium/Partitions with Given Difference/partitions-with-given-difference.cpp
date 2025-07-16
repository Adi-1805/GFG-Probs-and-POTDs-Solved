class Solution {
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
        
        dp[0][0] = 1;
        
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target; ++j) {
                dp[i][j] = dp[i-1][j];
                
                if (arr[i-1] <= j) {
                    dp[i][j] += dp[i-1][j - arr[i-1]];
                }
            }
        }
        
        return dp[n][target];
    }
  public:
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int n = arr.size();
        int total = accumulate(arr.begin(), arr.end(), 0);
        int target = (total-d)/2;
        // two things to check 
        // 1. target should not be negative
        if(target < 0) return 0;
        // 2. (total - d) should be even
        if( (total-d)&1 ) return 0;
        return perfectSum(arr, target);
        
    }
};