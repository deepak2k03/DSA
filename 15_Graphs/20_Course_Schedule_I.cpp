class Solution {
public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        queue<int>q;
        vector<int>adj[V];
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
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
        return topo;
    }
    bool canFinish(int V, vector<vector<int>>& edges) {
        vector<int>v=topoSort(V,edges);
        return v.size()==V;
    }
};