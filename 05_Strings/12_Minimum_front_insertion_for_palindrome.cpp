class Solution {
  public:
    
    void lpsFill(vector<int>&lps, string &s) {
        int pre=0, suf=1;
        while(suf<s.size()){
            if(s[pre]==s[suf]){
                lps[suf]=pre+1;
                pre++;
                suf++;
            }
            else{
                if(pre==0){
                    lps[suf]=0;
                    suf++;
                }
                else pre=lps[pre-1];
            }
        }
    }
        
    int minChar(string &s) {
        // code here
        string temp=s+'$';
        reverse(begin(s), end(s));
        temp+=s;
        vector<int>lps(temp.size(),0);
        lpsFill(lps, temp);
        return s.size()-lps.back();
    }
};
