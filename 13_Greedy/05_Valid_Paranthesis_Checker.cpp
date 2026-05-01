class Solution {
public:
    bool checkValidString(string s) {
        int mx=0,mn=0;
        for(auto i:s){
            if(i=='('){
                mn++;
                mx++;
            }
            else if(i==')'){
                mn--;
                mx--;
            }
            else{
                mn--;
                mx++;
            }
            if(mn<0) mn=0;
            if(mx<0) return false;
        }
        return mn==0;
    }
};