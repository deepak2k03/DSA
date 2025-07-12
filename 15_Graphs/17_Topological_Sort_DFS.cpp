class Solution {
  public:
    void dfs(int node, vector<int>& vis, stack<int>& s, vector<vector<int>>& adj) {
        vis[node] = 1;
        for (auto neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, vis, s, adj);
            }
        }
        s.push(node);
    }

    // edges: list of {u, v} meaning u → v
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<vector<int>> adj(V);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
        }

        vector<int> vis(V, 0);
        stack<int> s;

        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                dfs(i, vis, s, adj);
            }
        }

        vector<int> topo;
        while (!s.empty()) {
            topo.push_back(s.top());
            s.pop();
        }
        return topo;
    }
};
