class Solution {
  public:
    string decToBinary(int n) {
        // code here
        string res="";
        while(n){
            res+=to_string(n%2);
            n/=2;
        }
        reverse(begin(res),end(res));
        return res;
    }
};