class Solution {
public:
    bool isPalindrome(string s) {
        string ss = "";
        for (auto i : s){
            if ((i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') ||(i >= '0' && i <= '9')){
                ss.push_back(tolower(i));
            }
        }

        for (int i = 0; i < ss.size(); i++){
            if (ss[i] != ss[ss.size() - i - 1]){
                return false;
            }
        }
        return true;
    }
};