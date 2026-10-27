class Solution {
public:
    int largestDigit(int n) {
        int mx=0;
        while(n>0){
            int dig=n%10;
            mx=max(mx,dig);
            n/=10;
        }
        return mx;
    }
};