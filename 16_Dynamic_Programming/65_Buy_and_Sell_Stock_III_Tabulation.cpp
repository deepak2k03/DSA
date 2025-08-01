class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(3,0)));
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++){
                for(int cap=1;cap<=2;cap++){
                    int op1=0,op2=0;
                    if(buy){
                        op1=-prices[ind]+dp[ind+1][0][cap];
                        op2=dp[ind+1][1][cap];
                    }
                    else{
                        op1=prices[ind]+dp[ind+1][1][cap-1];
                        op2=dp[ind+1][0][cap];
                    }
                    dp[ind][buy][cap]=max(op1,op2);
                }
            }
        } 
        return dp[0][1][2];
    }
};
