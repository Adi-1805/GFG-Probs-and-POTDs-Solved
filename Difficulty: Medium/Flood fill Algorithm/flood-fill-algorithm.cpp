class Solution {
    int m, n;
    void solve(vector<vector<int>>& grid, int x, int y, int target, int curr){
        if(x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != curr){
            return ;
        }
        
        grid[x][y] = target;
        
        solve(grid, x+1, y, target, curr);
        solve(grid, x-1, y, target, curr);
        solve(grid, x, y+1, target, curr);
        solve(grid, x, y-1, target, curr);
    }
  public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc,
                                  int newColor){
        // Code here
        m = image.size();
        n = image[0].size();
        int curColor = image[sr][sc];
        if(curColor != newColor) solve(image, sr, sc, newColor, curColor);
        return image;
    }
};