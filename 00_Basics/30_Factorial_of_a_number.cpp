class Solution {
  public:
    int factorial(int n) {
        // code here
        if(n==0) return 1;
        int fact=1;
        while(n!=1){
            fact=fact*n;
            n--;
        }
        return fact;
    }
};