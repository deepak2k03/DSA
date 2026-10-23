//brute
class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        int a[26]={0};
        for(auto i:s) a[i-'a']++;
        char ans='a';
        int mx=0;
        for(auto i:s){
            if(a[i-'a']>mx) {
                mx = a[i-'a'];
                ans=i;
            }
            else if(a[i-'a']==mx && i<ans){
                mx=a[i-'a'];
                ans=i;
            }
        }
        return ans;
    }
};

//optimal
class Solution {
  public:
    char getMaxOccuringChar(string& s) {
        //  code here
        int a[26]={0};
        for(auto i:s) a[i-'a']++;
        char ans='a';
        int mx=0;
        for(char c='a'; c<='z';c++){
            if(a[c-'a']>mx){
                mx = a[c-'a'];
                ans = c;
            }
        }
        return ans;
    }
};
