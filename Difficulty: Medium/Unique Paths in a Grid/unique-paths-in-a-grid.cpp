class Solution {
    int m,n;
    vector<vector<int>> dp;    
    int solve(int x, int y, vector<vector<int>> &grid){
        if(x > m or y > n) return 0;
        if(grid[x][y] == 1) return 0;
        if(x == m-1 and y == n-1) return 1;
        if(dp[x][y] != -1) return dp[x][y];
        int down = 0, right = 0;
        if(x+1 < m) down = solve(x+1, y, grid);
        if(y+1 < n) right = solve(x, y+1, grid);
        return dp[x][y] = down + right;
    }
  public:
    int uniquePaths(vector<vector<int>> &grid) {
        // code here
        m = grid.size(); n = grid[0].size();
        // if the destination cell is a dead cell then the answer is 0
        // you can also put a check for the source cell but recursion takes care of it 
        if(grid[m-1][n-1] == 1) return 0;
        dp.resize(m, vector<int>(n, -1));
        return solve(0, 0, grid);
    }
};