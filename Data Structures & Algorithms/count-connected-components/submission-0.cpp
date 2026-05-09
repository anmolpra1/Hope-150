class Solution {
    vector<int> parent;
    vector<int> rank;
private:
    int find(int i) {
        if (i == parent[i]) {
            return i;
        }

        return parent[i] = find(parent[i]);
    }

    void DSU(int x, int y) {
        int x_parent = find(x);
        int y_parent = find(y);

        if (x_parent == y_parent) return;

        if (rank[x_parent] > rank[y_parent]) {
            parent[y_parent] = x_parent;
        }

        else if (rank[x_parent] < rank[y_parent]) {
            parent[x_parent] = y_parent;
        }

        else {
            parent[x_parent] = y_parent;
            rank[y_parent]++;
        }
    } 
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        rank.resize(n);
        parent.resize(n, 0);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
        int components = n;
        for (auto& it : edges) {
            int u = it[0];
            int v = it[1];

            if (find(u) != find(v)) {
                DSU(u, v);
                components--;
            }
        }

        return components;
    }
};
