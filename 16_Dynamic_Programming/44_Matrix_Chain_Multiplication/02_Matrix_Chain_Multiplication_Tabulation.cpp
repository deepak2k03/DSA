class Solution {
  public:
    int matrixMultiplication(vector<int> &arr) {
        // code here
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),0));
        // for(int i=1;i<arr.size();i++) dp[i][j]=0;
        for(int i=arr.size()-1;i>=1;i--){
            for(int j=i+1;j<arr.size();j++){
                int mini=1e9;
                for(int k=i;k<j;k++){
                    int steps=arr[i-1]*arr[k]*arr[j]+dp[i][k]+dp[k+1][j];
                    mini=min(mini,steps);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][arr.size()-1];
    }
};