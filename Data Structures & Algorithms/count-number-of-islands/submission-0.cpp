class Solution {
public:
    void bfs(int row, int col, vector<vector<char>>& grid,
             vector<vector<bool>>& vis) {

        int m = grid.size();
        int n = grid[0].size();

        int delrow[4] = {-1, 0, 1, 0};
        int delcol[4] = {0, 1, 0, -1};

        queue<pair<int,int>> q;
        q.push({row, col});
        vis[row][col] = true;

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int i = 0; i < 4; i++) {
                int nr = r + delrow[i];
                int nc = c + delcol[i];

                if(nr >= 0 && nr < m &&
                   nc >= 0 && nc < n &&
                   !vis[nr][nc] &&
                   grid[nr][nc] == '1') {

                    vis[nr][nc] = true;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        int islands = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {

                if(!vis[i][j] && grid[i][j] == '1') {
                    islands++;
                    bfs(i, j, grid, vis);
                }
            }
        }

        return islands;
    }
};