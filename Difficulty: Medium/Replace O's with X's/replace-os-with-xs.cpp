#include <vector>
using namespace std;

class Solution {
    int m, n;
    void dfs(vector<vector<char>>& grid, int x, int y) {
        if (x < 0 || x >= m || y < 0 || y >= n || grid[x][y] != 'O') {
            return;
        }
        grid[x][y] = '#'; // Mark as non-replaceable
        dfs(grid, x + 1, y);
        dfs(grid, x - 1, y);
        dfs(grid, x, y + 1);
        dfs(grid, x, y - 1);
    }
public:
    vector<vector<char>> fill(vector<vector<char>>& mat) {
        m = mat.size();
        if (m == 0) return mat;
        n = mat[0].size();
        
        for (int i = 0; i < m; ++i) {
            if (mat[i][0] == 'O') dfs(mat, i, 0);
            if (mat[i][n - 1] == 'O') dfs(mat, i, n - 1);
        }
        for (int j = 0; j < n; ++j) {
            if (mat[0][j] == 'O') dfs(mat, 0, j);
            if (mat[m - 1][j] == 'O') dfs(mat, m - 1, j);
        }
        
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (mat[i][j] == 'O') {
                    mat[i][j] = 'X';
                } else if (mat[i][j] == '#') {
                    mat[i][j] = 'O';
                }
            }
        }
        return mat;
    }
};