class Solution {
    int solve(vector<vector<int>>& arr, int i, int last, vector<vector<int>>& dp){
        if(i == 0){
            int maxCurr = 0;
            for(int j = 0; j < arr[0].size(); j++){  
                if(j != last) maxCurr = max(maxCurr, arr[i][j]);
            }
            return maxCurr;
        }
        if(dp[i][last] != -1) return dp[i][last];
        int maxCurr = 0;
        for(int j = 0; j < arr[0].size(); j++){  
            if(j != last){
                int curScore = arr[i][j] + solve(arr, i-1, j, dp);
                maxCurr = max(maxCurr, curScore);
            }
        }
        return dp[i][last] = maxCurr;
    }
public:
    int maximumPoints(vector<vector<int>>& arr) {
        int n = arr.size();
        if(n == 0) return 0;
        int tasks = arr[0].size(); 
        vector<vector<int>> dp(n, vector<int>(tasks + 1, -1));  // use tasks + 1
        return solve(arr, n-1, tasks, dp);  // pass tasks as initial last
    }
};