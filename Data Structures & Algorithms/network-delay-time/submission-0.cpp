class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
       vector<vector<pair<int, int>>> adj(n + 1);
        for (auto &it: times) {
            int u = it[0];
            int v = it[1];
            int t = it[2];
            adj[u].push_back({v, t}); // {u->{v, time}}
        }

       vector<int> dist(n + 1, 1e9);
        dist[k] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>,
                        greater<pair<int, int>>> pq;
        pq.push({0, k}); //(time taken, source)

        while (!pq.empty()) {
            int time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (time > dist[node]) continue;

            for (auto &nei : adj[node]) {
                int adjNode = nei.first;
                int currTime = nei.second;

                if (time + currTime < dist[adjNode]){
                dist[adjNode] = time + currTime;
                pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int ans = *max_element(dist.begin()+1, dist.end());
        return ans == 1e9 ? -1 : ans;

    }
};
