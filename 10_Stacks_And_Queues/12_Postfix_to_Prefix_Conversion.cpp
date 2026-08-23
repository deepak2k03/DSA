class Solution {
  public:
    string postToPre(string s) {
        stack<string> st;

        for (char ch : s) {
            if (isalnum(ch)) {      // Operand
                st.push(string(1, ch));
            } else {                // Operator
                string op2 = st.top(); st.pop();
                string op1 = st.top(); st.pop();

                string temp = string(1, ch) + op1 + op2;
                st.push(temp);
            }
        }

        return st.top();
    }
};