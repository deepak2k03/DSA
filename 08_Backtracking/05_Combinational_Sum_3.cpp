class Solution {
public:
    void f(int i, int k, int n,int sum, vector<int>&subset, vector<vector<int>>&ans){
        if (sum == n && subset.size() == k) {
            ans.push_back(subset);
            return;
        }
        if (sum > n || subset.size() > k || i > 9) return;
        //pick
        subset.push_back(i);
        f(i+1,k,n,sum+i,subset,ans);
        subset.pop_back();

        //not pick
        f(i+1,k,n,sum,subset,ans);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>v;
        vector<int>subset;
        f(1,k,n,0,subset,v);
        return v;
    }
};
