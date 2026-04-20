class Solution {
private:
    vector<int> topoSort(vector<vector<int>> &adj, vector<bool> &present) {
        vector<int> indegree(26, 0);

        for (int i = 0; i < 26; i++) {
            for (auto &it : adj[i]) {
                indegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < 26; i++) {
            if (present[i] && indegree[i] == 0) {
                q.push(i);
            }
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front(); q.pop();
            topo.push_back(node);

            for (auto &nei : adj[node]) {
                if (--indegree[nei] == 0) {
                    q.push(nei);
                }
            }
        }

        return topo;
    }

public:
    string foreignDictionary(vector<string>& words) {
        vector<vector<int>> adj(26);
        vector<bool> present(26, false);

        // mark present chars
        for (auto &w : words)
            for (char c : w)
                present[c - 'a'] = true;

        for (int i = 0; i < words.size() - 1; i++) {
            string s1 = words[i], s2 = words[i+1];
            int len = min(s1.size(), s2.size());

            bool found = false;

            for (int j = 0; j < len; j++) {
                if (s1[j] != s2[j]) {
                    adj[s1[j]-'a'].push_back(s2[j]-'a');
                    found = true;
                    break;
                }
            }

            if (!found && s1.size() > s2.size()) return "";
        }

        vector<int> topo = topoSort(adj, present);

        int count = 0;
        for (bool p : present) if (p) count++;

        if (topo.size() != count) return ""; // cycle

        string ans = "";
        for (int x : topo) ans += char(x + 'a');
        return ans;
    }
};