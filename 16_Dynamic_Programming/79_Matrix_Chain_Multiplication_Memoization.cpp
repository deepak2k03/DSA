class Solution {
  public:
    int f(int i, int j, vector<int>& arr, vector<vector<int>>& dp){
        if(i==j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int mini=1e9;
        for(int k=i;k<j;k++){
            int steps=arr[i-1]*arr[k]*arr[j]+f(i,k,arr,dp)+f(k+1,j,arr,dp);
            mini=min(mini,steps);
        }
        return dp[i][j]=mini;
    }
    int matrixMultiplication(vector<int> &arr) {
        // code here
        vector<vector<int>>dp(arr.size(),vector<int>(arr.size(),-1));
        return f(1,arr.size()-1,arr,dp);
    }
};