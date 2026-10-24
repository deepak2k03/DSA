class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int mn=INT_MAX;
        string s="";
        string t="";
        for(auto i:strs){
            if(i.size()<mn){
                mn=i.size();
                s=i;
            }
        }
        int j=0;
        for(int i=0;i<mn;i++){
            char ch=s[j];
            for(auto i:strs)if(i[j]!=ch) return t;
            t+=ch;
            j++;
        }
        return t;
    }
};