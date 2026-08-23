class Solution {
  public:
    string preToPost(string &s) {
        stack<string> st;

        for (int i = s.size() - 1; i >= 0; i--) {
            char ch = s[i];

            if (isalnum(ch)) {          // Operand
                st.push(string(1, ch));
            } else {                    // Operator
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();

                string temp = op1 + op2 + ch;
                st.push(temp);
            }
        }

        return st.top();
    }
};