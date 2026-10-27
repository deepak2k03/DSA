// User function Template for C++
class Solution {
  public:
    string armstrongNumber(int n){
        // code here
        int n_copy=n;
        int sum=0;
        while(n!=0){
            int x=n%10;
            sum+=x*x*x;
            n=n/10;
        }
        if(sum==n_copy){
            return "Yes";
        }
        return "No";
    }
};