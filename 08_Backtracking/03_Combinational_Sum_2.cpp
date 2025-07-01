class Solution {
public:
    void solve(int target,int index,vector<int>&candidates, vector<int>&temp,vector<vector<int>>&v){
        if(index==candidates.size() ){
            v.push_back(temp);
            return;
        }
        for(int i=index;i<candidates.size();i++){
            if(i>index && candidates[i]==candidates[i-1]) continue;
            if(candidates[i]>target) break;
            temp.push_back(candidates[i]);
            solve(target-candidates[i],i+1,candidates,temp,v);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(begin(candidates),end(candidates));
        vector<vector<int>>v;
        vector<int>temp;
        solve(target,0,candidates,temp,v);
        return v;
    }
};
