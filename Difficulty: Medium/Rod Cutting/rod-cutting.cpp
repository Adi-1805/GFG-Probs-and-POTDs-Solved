// User function Template for C++

class Solution {
    int n = 0, total = 0;
    // KINDA CONVERTED THE FUNCTION TO SUIT THE 1-BASED INDEXING
    int solve(int ind, int length, vector<int>& price, vector<vector<int>>& dp){
        if(ind == 0){
            return (length)*price[0];
        }
        if(dp[ind][length] != -1) return dp[ind][length];
        int not_take = solve(ind-1, length, price, dp);
        int take = -1e9;
        if(ind+1 <= length) take = price[ind] + solve(ind, length-(ind+1), price, dp);
        return dp[ind][length] = max(take, not_take);
    }
  public:
    int cutRod(vector<int> &price) {
        // code here
        n = price.size();
        total = accumulate(price.begin(), price.end(), 0);
        vector<vector<int>> dp(n, vector<int>(n+1, -1));
        return solve(n-1, n, price, dp);
        
    }
};