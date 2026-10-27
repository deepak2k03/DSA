class Solution {
public:
    int countDigits(long long n) {
        n=abs(n);
        int c=0;
        if(n==0) return 1;
        while(n){
            c++;
            n/=10;
        }
        return c;
    }
};
