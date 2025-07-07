class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        int mx=0,l=0,r=0;
        map<char,int>m;
        while(r<s.size()){
            m[s[r]]++;
            if(m.size()>k){
                m[s[l]]--;
                if(m[s[l]]==0) m.erase(s[l]);
                l++;
            }
            if(m.size()==k) mx=max(mx,r-l+1);
            r++;
        }
        return mx==0?-1:mx;
    }
};