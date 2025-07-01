class Solution {
public:
    bool isPalindrome(string s){
        for(int i=0;i<s.size()/2;i++) if(s[i]!=s[s.size()-i-1]) return false;
        return true;
    }
    void f(int index, string& s, vector<string>& temp, vector<vector<string>>& res){
        int n=s.size();
        if(index==n){
            res.push_back(temp);
            return;
        }
        for(int i=index;i<n;i++){
            string ss=s.substr(index, i-index+1);
            if(isPalindrome(ss)){ 
                temp.push_back(ss);
                f(i+1,s,temp,res);
                temp.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>temp;
        f(0,s,temp,res);
        return res;
    }
};
