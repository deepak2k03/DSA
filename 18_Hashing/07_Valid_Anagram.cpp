class Solution {
public:
    bool isAnagram(string s, string t) {
        int a[26]={0}, b[26]={0};
        for(auto i:s) a[i-'a']++;
        for(auto i:t) b[i-'a']++;
        for(char c='a';c<='z';c++) if(a[c-'a']!=b[c-'a']) return false;
        return true;
    }
};