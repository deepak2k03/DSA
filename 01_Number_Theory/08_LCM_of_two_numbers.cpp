//by iteration -- brute
class Solution {
  public:
    int lcm(int a, int b) {
        // code here
        int ans;
        for(int i=min(a,b);i<=a*b;i++){
            if(i%a==0 && i%b==0){
                ans=i;
                break;
            }
        }
        return ans;
    }
};


//lcm by checking multiples of larger number - better
class Solution {
  public:
    int lcm(int a, int b) {
        // code here
        int mx=max(a,b);
        int mn=min(a,b);
        int temp=mx;
        while(temp%mn!=0){
            temp+=mx;
        }
        return temp;
    }
};


//using GCD method -- Best
class Solution {
  public:
    int lcm(int a, int b) {
        // code here
        return (a*b)/(__gcd(a,b));
    }
};