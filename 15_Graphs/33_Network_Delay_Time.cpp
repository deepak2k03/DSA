class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i:times) adj[i[0]].push_back({i[1],i[2]});
        vector<int>dist(n+1,1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        pq.push({0,k});
        dist[k]=0;
        while(!pq.empty()){
            auto [time, node] = pq.top();
            pq.pop();
            for (auto& [nei, wt] : adj[node]) {
                if (dist[node] + wt < dist[nei]) {
                    dist[nei] = dist[node] + wt;
                    pq.push({dist[nei], nei});
                }
            }
        }
        int maxTime = *max_element(dist.begin() + 1, dist.end());
        return maxTime == 1e9 ? -1 : maxTime; 
    }
};