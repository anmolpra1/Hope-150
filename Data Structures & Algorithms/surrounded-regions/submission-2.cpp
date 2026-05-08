class Solution {

    int delrow[4] = {-1, 0, 1, 0};
    int delcol[4] = {0, 1, 0, -1};
    int m, n;

private:
    void dfs(int i, int j, vector<vector<char>>& board, vector<vector<bool>> &vis)
    {
        vis[i][j] = true;
        board[i][j] = '@';

        for (int dir = 0; dir < 4; dir++) {
            int nr = i + delrow[dir];
            int nc = j + delcol[dir];

            if (nr >= 0 && nr < m && nc >= 0 && nc < n
            && !vis[nr][nc] && board[nr][nc] == 'O') {
                board[nr][nc] = '@';
                dfs(nr, nc, board, vis);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();

        vector<vector<bool>> vis(m, vector<bool>(n, false));

        for (int col = 0; col < n; col++) {
            if (board[0][col] == 'O') {
                dfs(0, col, board, vis);
            }
            
            if(board[m-1][col] == 'O') {
                dfs(m - 1, col, board, vis);
            }
        }

        for (int row = 0; row < m; row++) {
            if (board[row][0] == 'O') {
                dfs(row, 0, board, vis);
            }
            
            if(board[row][n-1] == 'O') {
                dfs(row, n - 1, board, vis);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '@') {
                    board[i][j] = 'O';
                }

                else if (board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
    }
};
