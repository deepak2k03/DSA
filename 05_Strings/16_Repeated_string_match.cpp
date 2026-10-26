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

    bool search(string& a, string& b) {
        vector<int> lps(b.size(), 0);
        lpsFill(lps, b);

        int i = 0, j = 0;

        while (i < a.size()) {
            if (a[i] == b[j]) {
                i++;
                j++;

                if (j == b.size())
                    return true;
            } else {
                if (j == 0)
                    i++;
                else
                    j = lps[j - 1];
            }
        }

        return false;
    }

    int repeatedStringMatch(string a, string b) {
        string temp = a;
        int rep = 1;

        while (temp.size() < b.size()) {
            temp += a;
            rep++;
        }

        if (search(temp, b))
            return rep;

        // One additional repetition may allow a boundary-spanning match
        temp += a;

        if (search(temp, b))
            return rep + 1;

        return -1;
    }
};