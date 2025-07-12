class Solution {
public:
    vector<int> findOrder(int V, vector<vector<int>>& edges) {
        queue<int>q;
        vector<int>adj[V];
        for (auto& edge : edges) {
            int u = edge[1], v = edge[0];
            adj[u].push_back(v);
        }
        vector<int>indegree(V);
        for(int u=0;u<V;u++) for(auto v:adj[u]) indegree[v]++;
        for(int i=0;i<V;i++) if(indegree[i]==0) q.push(i);
        vector<int>topo;
        while(!q.empty()){
            int node=q.front();
            topo.push_back(node);
            q.pop();
            for(auto i:adj[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
            
        }
        if(topo.size()==V) return topo;
        else return {};
    }
};