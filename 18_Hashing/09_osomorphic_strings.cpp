class Solution {
public:
    string f(string st){
        map<char,char>m;
        char j='a';
        string res="";
        for(auto i:st){
            if(m.find(i)==m.end()){
                m[i]=j;
                j++;
            }
        }
        for(auto i:st) res+=(m[i]);
        return res;
    }
    bool isIsomorphic(string s, string t) {
        return f(s)==f(t);
    }
};