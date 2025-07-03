class Solution {
  public:
    bool detect(int src, vector<vector<int>>& adj, vector<int>& vis) {
        vis[src] = 1;
        queue<pair<int, int>> q;
        q.push({src, -1});
        while (!q.empty()) {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            for (auto i : adj[node]) {
                if (!vis[i]) {
                    vis[i] = 1;
                    q.push({i, node});
                } else if (parent != i) {
                    return true;
                }
            }
        }
        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            int u = edge[0];  // NO -1 here
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> vis(V, 0);
        for (int i = 0; i < V; i++) {
            if (!vis[i]) {
                if (detect(i, adj, vis)) return true;
            }
        }
        return false;
    }
};
