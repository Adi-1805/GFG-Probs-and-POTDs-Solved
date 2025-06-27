class Solution {
  public:
    int minCost(vector<int>& height) {
        // Code here
        int n = height.size();
        vector<int> dp(n, 0);
        dp[0] = 0;
        for(int i = 0; i < n; i++){
            int way1 = 0, way2 = INT_MAX;
            if(i > 0) way1 = dp[i-1] + abs(height[i] - height[i-1]);
            if(i > 1) way2 = dp[i-2] + abs(height[i] - height[i-2]);
            dp[i] = min(way1, way2);
        }
        return dp[n-1];
        
    }
};