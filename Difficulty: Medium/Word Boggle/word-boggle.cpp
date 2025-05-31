class Solution {
    int m,n;
    void dfs(vector<vector<char>>& grid, string s, int ind, vector<string>& ans, int x, int y, vector<vector<bool>>& vis){
        if(ind == s.size()){ ans.push_back(s); return; }
        if(x < 0 || x >= m || y < 0 || y >= n || ind > s.size() || grid[x][y] != s[ind] || vis[x][y]){
            return ;
        }
        
        vis[x][y] = 1;
        dfs(grid, s, ind+1, ans, x+1, y, vis); 
        dfs(grid, s, ind+1, ans, x-1, y, vis);
        dfs(grid, s, ind+1, ans, x, y+1, vis);
        dfs(grid, s, ind+1, ans, x, y-1, vis);
        dfs(grid, s, ind+1, ans, x+1, y+1, vis);
        dfs(grid, s, ind+1, ans, x-1, y-1, vis);
        dfs(grid, s, ind+1, ans, x-1, y+1, vis);
        dfs(grid, s, ind+1, ans, x+1, y-1, vis);
        vis[x][y] = 0;
    }
  public:
    vector<string> wordBoggle(vector<vector<char> >& board,
                              vector<string>& dictionary) {
        // Code here
        vector<string> ans;
        m = board.size();
        n = board[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,0)); 
        for(string word: dictionary){
            bool found = 0;
            for(int i = 0; i < m and !found; i++){
                for(int j = 0; j < n and !found; j++){
                    // cout << i << " " << j << endl;
                    if(word[0] == board[i][j]){
                        dfs(board, word, 0, ans, i, j, visited);
                        if(!ans.empty() and word == ans.back()) found = 1;
                    }
                }
            }
        }
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};