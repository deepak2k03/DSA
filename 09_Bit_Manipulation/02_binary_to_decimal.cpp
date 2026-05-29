class Solution {
  public:
    int binaryToDecimal(string &b) {
        // Code here.
        int n=b.size()-1;
        int ans=0;
        for(auto i:b){
            ans+=int(i-'0')*pow(2,n);
            n--;
        }
        return ans;
    }
};