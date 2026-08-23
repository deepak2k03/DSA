class Solution {
  public:
    string postToInfix(string &exp) {
        // Write your code here
        stack<string>st;
        for(auto i:exp){
            if(isalnum(i)){
                st.push(string(1,i));
            }
            else{
                string op2=st.top();
                st.pop();
                string op1=st.top();
                st.pop();
                string temp="("+op1+i+op2+")";
                st.push(temp);
            }
        }
        return st.top();
    }
};