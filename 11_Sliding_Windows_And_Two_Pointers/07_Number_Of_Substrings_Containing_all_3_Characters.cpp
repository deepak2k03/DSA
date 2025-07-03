class Solution {
public:
    int numberOfSubstrings(string s) {
        int c=0;
        int ls[3]={-1,-1,-1};
        for(int i=0;i<s.size();i++){
            ls[s[i]-'a']=i;
            if(ls[0]!=-1 && ls[1]!=-1 && ls[0]!=-3) c+=1+min({ls[0],ls[1],ls[2]});
        }
        return c;
    }
};