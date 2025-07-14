class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Step 1: Create adjacency list
        vector<vector<pair<int, int>>> adj(V);
        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w});
            adj[v].push_back({u, w}); // Remove if the graph is directed
        }

        // Step 2: Distance array
        vector<int> dist(V, 1e9);
        dist[src] = 0;

        // Step 3: Set for {distance, node}
        set<pair<int, int>> st;
        st.insert({0, src});

        // Step 4: Dijkstra's algorithm
        while (!st.empty()) {
            auto it = *(st.begin());
            int dis = it.first;
            int node = it.second;
            st.erase(it);

            for (auto &nbr : adj[node]) {
                int adjNode = nbr.first;
                int edgeWeight = nbr.second;

                if (dis + edgeWeight < dist[adjNode]) {
                    // Remove old pair if it exists
                    if (dist[adjNode] != 1e9) {
                        st.erase({dist[adjNode], adjNode});
                    }

                    // Update distance and insert new pair
                    dist[adjNode] = dis + edgeWeight;
                    st.insert({dist[adjNode], adjNode});
                }
            }
        }

        return dist;
    }
};
