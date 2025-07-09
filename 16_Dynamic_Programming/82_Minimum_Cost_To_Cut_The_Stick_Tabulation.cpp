class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(n);
        cuts.insert(begin(cuts),0);
        sort(begin(cuts),end(cuts));
        vector<vector<int>>dp(cuts.size(),vector<int>(cuts.size(),0));
        for(int i=cuts.size()-2;i>=1;i--){
            for(int j=1;j<=cuts.size()-2;j++){
                if(i>j) continue;
                int mini=1e9;
                for(int ind=i;ind<=j;ind++){
                    int cost=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                    mini=min(cost,mini);
                }
                dp[i][j]=mini;                
            }
        }
        return dp[1][cuts.size()-2];
    }
};