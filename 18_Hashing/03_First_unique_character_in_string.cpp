class Solution {
  public:
    char nonRepeatingChar(string &s) {
        //  code here
        int a[26]={0};
        for(auto i:s) a[i-'a']++;
        char ans='$';
        for(auto i:s){
            if(a[i-'a']==1) {
                ans=i;
                break;
            }
        }
        return ans;
    }
};