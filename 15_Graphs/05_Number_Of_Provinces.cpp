class Solution {
public:
    void dfss(vector<vector<int>>& adj, int node, vector<int> &vis){
        vis[node]=1;
        for(int i=0;i<adj.size();i++) if(adj[node][i] == 1 && !vis[i]) dfss(adj, i, vis);
    }
    int findCircleNum(vector<vector<int>>& adj) {
        int n=adj.size();
        int c=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++) if(!vis[i]) {c++;dfss(adj,i,vis);}
        return c;
    }
};
