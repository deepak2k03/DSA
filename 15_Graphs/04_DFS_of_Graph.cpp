class Solution {
  public:
    void dfss(vector<vector<int>>& adj, int node, int vis[], vector<int> &store){
        vis[node]=1;
        store.push_back(node);
        for(auto i:adj[node]) if(!vis[i]) dfss(adj, i, vis, store);
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int vis[adj.size()]={0};
        vector<int>store;
        dfss(adj,0,vis,store);
        return store;
    }
};
