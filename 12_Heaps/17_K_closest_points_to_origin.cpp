class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>>v;
        priority_queue<pair<int,pair<int,int>>>maxh;
        for(auto i:points){
            maxh.push({i[0]*i[0] + i[1]*i[1],{i[0],i[1]}});
            if(maxh.size()>k) maxh.pop();
        }
        while(!maxh.empty()){
            v.push_back({maxh.top().second.first,maxh.top().second.second});
            maxh.pop();
        }
        return v;
    }
};