class Solution {
  public:
    int maxChildren(vector<int> &greed, vector<int> &cookie) {
        // Your Code goes here.
        sort(begin(greed),end(greed));
        sort(begin(cookie),end(cookie));
        int l=0,r=0;
        while(l<cookie.size() && r<greed.size()){
            if(cookie[l]>=greed[r]) r++;
            l++;
        }
        return r;
    }
};