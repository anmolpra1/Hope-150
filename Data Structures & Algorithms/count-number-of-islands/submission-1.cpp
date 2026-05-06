class Solution {

    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};
    int m, n;

private:
    void DFS(int row, int col, vector<vector<bool>> &vis, vector<vector<char>>& grid) {
        vis[row][col] = true;

        for (int i = 0; i < 4; i++) {
            int nr = row + delrow[i];
            int nc = col + delcol[i];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n && !vis[nr][nc] && grid[nr][nc] == '1') {
                DFS(nr, nc, vis, grid);
            }
        }   
    }    
public:
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int islands = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!vis[i][j] && grid[i][j] == '1') {
                    DFS(i, j, vis, grid);
                    islands++;
                }
            }
        }
        return islands;
    }
};
