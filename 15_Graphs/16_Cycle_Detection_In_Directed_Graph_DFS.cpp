class Solution {
public:
    bool dfs(int node, vector<int> adj[], vector<bool>& vis, vector<bool>& pathVis) {
        vis[node] = pathVis[node] = true;

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                if (dfs(nei, adj, vis, pathVis)) return true;
            } else if (pathVis[nei]) {
                // Found a back edge (cycle)
                return true;
            }
        }

        pathVis[node] = false; // backtrack
        return false;
    }

    bool isCyclic(int V, vector<vector<int>>& edges) {
        // Build adjacency list
        vector<int> adj[V];
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
        }

        vector<bool> vis(V, false), pathVis(V, false);

        for (int i = 0; i < V; ++i) {
            if (!vis[i]) {
                if (dfs(i, adj, vis, pathVis)) return true;
            }
        }

        return false;
    }
};
