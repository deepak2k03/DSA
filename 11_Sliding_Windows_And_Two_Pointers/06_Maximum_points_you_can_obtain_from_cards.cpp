class Solution {
  public:
    int maxScore(vector<int>& v, int k) {
        // code here.
        int ls=0, rs=0, mx=0;
        for(int i=0;i<k;i++) ls+=v[i];
        mx=ls;
        int ridx=v.size()-1;
        for(int i=k-1;i>=0;i--){
            ls-=v[i];
            rs+=v[ridx--];
            mx=max(ls+rs,mx);
        }
        return mx;
    }
};
