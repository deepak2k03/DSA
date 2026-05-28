// User function Template for C++

class Solution {
  public:
    long long int power(int a, long long int b) {
        // complete the function here
        long long res=1;
        long long m=1e9+7;
        while(b){
            if(b%2){
                res=(res*a)%m;
                b--;
            }
            else{
                a=((long long)a*a)%m;
                b/=2;
            }
        }
        return res;
    }
};
