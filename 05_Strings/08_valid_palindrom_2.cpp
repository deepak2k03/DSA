class Solution {
public:
    bool pal(int left, int right, string s){
        while(left<=right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
    bool validPalindrome(string s) {
        int left=0,right=s.size()-1;
        while(left<=right){
            if(s[left]!=s[right]){
                return pal(left+1, right, s) || pal(left, right-1, s);
            }
            else{
                left++;
                right--;
            }
        }
        return true;
    }
};