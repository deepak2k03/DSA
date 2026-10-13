class Solution {
  public:
    int findMin(int n) {
        // code here
        int c=0;
        c+=n/10;
        n=n%10;
        c+=n/5;
        n=n%5;
        c+=n/2;
        n=n%2;
        c+=n;
        return c;
        
    }
};