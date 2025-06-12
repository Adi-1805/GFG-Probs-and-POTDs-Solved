class Solution {
    int m,n;
    int drow[8] = {-1,1,0,0,-1,-1,1,1};
    int dcol[8] = {0,0,-1,1,-1,1,-1,1};
    void dfs(int x, int y, vector<vector<char>>& grid, vector<vector<bool>>& vis){
        if(x < 0 or x >= m or y < 0 or y >= n or vis[x][y] or grid[x][y] != 'L') return;
        vis[x][y] = 1; 
        for(int i = 0; i < 8; i++){
            dfs(x+drow[i], y+dcol[i], grid, vis);
        }
    }
  public:
    int countIslands(vector<vector<char>>& grid) {
        // Code here
        m = grid.size();
        n = grid[0].size();
        int cnt = 0;
        vector<vector<bool>> vis(m, vector<bool>(n,0));
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(!vis[i][j] and grid[i][j] == 'L'){
                    cnt++;
                    dfs(i ,j , grid, vis);
                }
            }
        }
        return cnt;
    }
};