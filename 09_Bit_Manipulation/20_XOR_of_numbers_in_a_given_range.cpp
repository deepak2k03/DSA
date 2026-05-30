// L TO R = (1 TO L XOR) ^ (L TO R XOR)
class Solution {
  public:
    int XOR(int n){
        if(n%4==0) return n;
        if(n%4==1) return 1;
        if(n%4==2) return n+1;
        if(n%4==3) return 0;
    }
    int findXOR(int l, int r) {
        // code here
        return XOR(l-1)^XOR(r);
    }
};