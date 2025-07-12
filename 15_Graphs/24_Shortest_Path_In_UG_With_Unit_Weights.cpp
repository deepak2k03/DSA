class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& adj, int src) {
        int V = adj.size(); // number of vertices
        vector<int> dist(V, -1); // initialize all distances as -1
        queue<int> q;

        dist[src] = 0;
        q.push(src);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                }
            }
        }
        return dist;
    }
};
