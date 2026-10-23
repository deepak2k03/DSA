class Solution {
public:
    char findTheDifference(string s, string t) {
        int a[26];
        for(auto i:s) a[i-'a']++;
        for(auto i:t) a[i-'a']++;
        char ans='z';
        for(int i=0;i<26;i++) if(a[i]%2) ans='a'+i;
        return ans;
    }
};