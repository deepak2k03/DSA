class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>m;
        for(auto i:nums) m[i]++;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>minh;
        for(auto [num, freq] : m) {
            minh.push({freq, num});
            if(minh.size() > k) minh.pop();
        }
        vector<int>v;
        while(!minh.empty()){
            v.push_back(minh.top().second);
            minh.pop();
        }
        return v;
    }
};