class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights,
                          int src, int dst, int k) {

        vector<vector<pair<int,int>>> adj(n);

        for(auto &f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        queue<vector<int>> q;
        q.push({0, src, 0}); // stops, node, cost

        vector<int> dist(n, 1e9);
        dist[src] = 0;

        while(!q.empty()) {

            auto cur = q.front();
            q.pop();

            int stops = cur[0];
            int node  = cur[1];
            int cost  = cur[2];

            if(stops > k) continue;

            for(auto &it : adj[node]) {

                int nei = it.first;
                int wt  = it.second;

                if(cost + wt < dist[nei]) {

                    dist[nei] = cost + wt;

                    q.push({
                        stops + 1,
                        nei,
                        cost + wt
                    });
                }
            }
        }

        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};