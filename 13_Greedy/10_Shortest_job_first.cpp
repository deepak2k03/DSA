class Solution {
  public:
    int solve(vector<int>& bt) {
        // code here
        sort(begin(bt), end(bt));
        int t=0, wt=0;
        for(int i=0;i<bt.size();i++){
            wt=wt+t;
            t=t+bt[i];
        }
        return wt/bt.size();
    }
};