class Solution {
public:
    int numDistinct(string s, string t) {
        vector<vector<double>>dp(s.size()+1,vector<double>(t.size()+1,0));
        for(int i=0;i<=s.size();i++) dp[i][0]=1;
        for(int j=1;j<=t.size();j++) dp[0][j]=0;
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]) dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                else dp[i][j]=dp[i-1][j];
            }
        }
        return (int)dp[s.size()][t.size()];
    }
};
