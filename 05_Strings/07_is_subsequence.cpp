class Solution {
public:
    bool isSubsequence(string s, string t) {
        vector<int>v;
        int j=0;
        for(int i=0;i<t.size() && j<s.size();i++) if(t[i]==s[j]) j++;
        return j==s.size();
    }
};