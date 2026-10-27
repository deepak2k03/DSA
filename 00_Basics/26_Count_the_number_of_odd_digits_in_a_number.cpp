class Solution {
public:
    int countOddDigit(int n) {
        int c=0;
        while(n>0){
            int dig=n%10;
            if(dig%2) c++;
            n/=10;
        }
        return c;
    }
};