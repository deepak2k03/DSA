class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<vector<int>>revAdj(n);
        for (int u=0;u<n;u++) for (int v:graph[u]) revAdj[v].push_back(u); 
        vector<int>indegree(n,0);
        for(int i=0;i<n;i++) for(auto j:revAdj[i]) indegree[j]++;
        queue<int>q;
        vector<int>safe;
        for(int i=0;i<n;i++) if(indegree[i]==0) q.push(i);
        while(!q.empty()){
            int node=q.front();
            q.pop();
            safe.push_back(node);
            for(auto i:revAdj[node]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        sort(begin(safe),end(safe));
        return safe;
    }
};