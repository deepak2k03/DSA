class Solution {
public:
    void lpsFill(vector<int>& lps, string& s) {
        int pre = 0, suf = 1;

        while (suf < s.size()) {
            if (s[pre] == s[suf]) {
                lps[suf] = pre + 1;
                pre++;
                suf++;
            } else {
                if (pre == 0) {
                    lps[suf] = 0;
                    suf++;
                } else {
                    pre = lps[pre - 1];
                }
            }
        }
    }
    string longestPrefix(string s) {
        vector<int> lps(s.size(), 0);
        lpsFill(lps, s);
        string temp="";
        for(int i=0;i<lps.back();i++) temp+=s[i];
        return temp;
    }
};