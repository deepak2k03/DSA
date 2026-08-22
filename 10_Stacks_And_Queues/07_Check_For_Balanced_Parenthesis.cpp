class Solution {
  public:
    bool isBalanced(string& s) {
        // code here
        stack<char>st;
        for(auto i:s){
            if(i=='(' || i== '{' || i== '['){
                st.push(i);
            }
            else{
                if(st.empty()) return false;
                char temp=st.top();
                st.pop();
                if(i==')' && temp !='(' ||
                i=='}' && temp !='{' ||
                i==']' && temp !='[')
                return false;
            }
        }
        return st.empty();
    }
};