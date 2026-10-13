class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(begin(intervals),end(intervals));
        int n=intervals.size();
        vector<vector<int>>v;
        for(int i=0;i<n;i++){
            if(v.empty()||v.back()[1]<intervals[i][0]) v.push_back(intervals[i]);
            else v.back()[1]=max(v.back()[1],intervals[i][1]);
        }
        return v;
    }
};