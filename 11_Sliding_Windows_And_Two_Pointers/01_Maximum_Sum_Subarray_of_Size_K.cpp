class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n=arr.size();
        int cur=0;
        int mx=0;
        int start=0;
        int end=0;
        int sum=0;
        //create window of size k
        for(end=0;end<k;end++) sum+=arr[end];
        mx=sum;
        //move the window
        while(end<n){
            sum-=arr[start++];
            sum+=arr[end++];
            mx=max(mx,sum);
        }
        return mx;
    }
};