class Solution {
  public:
    int longestKSubstr(string &s, int k) {
        // code here
        map<char, int>m;
        int mx=-1;
        int i=0,j=0;
        while(j<s.size()){
            m[s[j]]++;
            if(m.size()==k) mx=max(mx,j-i+1);
            else if(m.size()>k){
                while(m.size()>k && i<j){
                    m[s[i]]--;
                    if(m[s[i]]<=0) m.erase(s[i]);
                    i++;
                }
            }
            j++;
        }
        return mx;
    }
};