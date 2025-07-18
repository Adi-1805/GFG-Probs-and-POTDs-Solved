class Solution {
    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        int zeroes = 0;
        for(int val: arr) if(val == 0) zeroes++;
        vector<vector<int>> dp(n, vector<int>(target + 1, 0));
        
        for(int i = 0; i < n; i++) dp[i][0] = 1;
        if(arr[0] <= target) dp[0][arr[0]] = 1;
        
        for (int i = 1; i < n; ++i) {
            for (int j = 1; j <= target; ++j) {
                int not_take = dp[i-1][j], take = 0;
                
                if (arr[i] <= j  and arr[i] != 0) {
                    take = dp[i-1][j - arr[i]];
                }
                dp[i][j] = take+not_take;
            }
        }
        
        return dp[n-1][target]*pow(2, zeroes);
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