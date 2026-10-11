//using iteration -- brute
class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        int ans;
        for(int i=1;i<=min(a,b);i++){
            if(a%i==0 && b%i==0){
                ans=i;
            }
        }
        return ans;
    }
};

//using euclid algo -- best
class Solution {
  public:
    int gcd(int a, int b) {
        // code here
        if(a%b==0) return b;
        // or if(b==a) return a; bs ek call aur badh jaegi
        return gcd(b,a%b);
    }
};

