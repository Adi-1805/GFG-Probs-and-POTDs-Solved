class Solution {
    int drow[8] = {-1, 1, 0, 0, -1, -1, 1, 1};
    int dcol[8] = {0, 0, 1, -1, 1, -1, 1, -1};
    int m, n;
    
    char getDir(int i, int j){
        if(i == -1 and j == 0) return 'U';
        if(i == 1 and j == 0) return 'D';
        if(i == 0 and j == 1) return 'R';
        if(i == 0 and j == -1) return 'L';
    }
    void help(int r, int c, vector<vector<int>>& maze, vector<vector<bool>> &vis, vector<string> &results, string path){
        if(r < 0 or r >= m or c < 0 or c >= n or vis[r][c] or maze[r][c] == 0) return;
        if(r == m-1 and c == n-1){
            results.push_back(path);
            return;
        }
        
        vis[r][c] = 1;
        for(int i = 0; i < 4; i++){
            char dir = getDir(drow[i], dcol[i]);
            help(r + drow[i], c + dcol[i], maze, vis, results, path+dir);
        }
        vis[r][c] = 0;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        m = maze.size();
        n = maze[0].size();
        vector<string> results;
        vector<vector<bool>> vis(m, vector<bool>(n, 0));
        string path = "";
        help(0, 0, maze, vis, results, path);
        sort(results.begin(), results.end());
        return results;
    }
};