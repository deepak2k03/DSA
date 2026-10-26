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

    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        string temp = s + "#" + rev;

        vector<int> lps(temp.size(), 0);
        lpsFill(lps, temp);

        int len = lps.back();

        string add = s.substr(len);
        reverse(add.begin(), add.end());

        return add + s;
    }
};