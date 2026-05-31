class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();

        //Create min heap
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> minHeap;

        vector<vector<int>> vis(n, vector<int>(n, 0));

        //push the statrting cell to heap
        minHeap.push({grid[0][0], 0, 0});
        vis[0][0] = 1;

         // Direction vectors for movement
        vector<pair<int, int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        while (!minHeap.empty()) {
            auto curr = minHeap.top();
            minHeap.pop();

            int elevation = curr[0], r = curr[1], c = curr[2];

            //if destination is reached, return elevation
            if (r == n - 1 && c == n - 1) return elevation;

            //explore all nei cells
            for (auto &nei : dir) {
                int nr = r + nei.first;
                int nc = c + nei.second;

                if (nr >= 0 && nc >= 0 && nr < n && nc < n && !vis[nr][nc]) {
                    vis[nr][nc] = 1;
                    minHeap.push({max(elevation, grid[nr][nc]), nr, nc});
                }
            }
        }
        return -1;
    }
};