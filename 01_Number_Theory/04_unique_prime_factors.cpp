class Solution {
  public:
    vector<int> primeFac(int n) {
        // code here
        set<int>s;
        for(int i=2;i*i<=n;i++){
            while(n%i==0) {
                s.insert(i);
                n/=i;
            }
        }
        if(n>1) s.insert(n);
        vector<int>ans;
        for(auto i:s) ans.push_back(i);
        return ans;
    }
};