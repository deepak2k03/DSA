// 1. reverse the infix (op brack to cl brac, cl brac to op brac)
// 2. perform infix to postfix (controlled <= to <)
// 3. reverse the ans

class Solution {
    public:
      int priority(char ch) {
          if (ch == '^') return 3;
          if (ch == '*' || ch == '/') return 2;
          if (ch == '+' || ch == '-') return 1;
          return -1;
      }

      string infixToPrefix(string &s) {

          reverse(s.begin(), s.end());

          for (char &ch : s) {
              if (ch == '(') ch = ')';
              else if (ch == ')') ch = '(';
          }

          stack<char> st;
          string postfix = "";

          for (char ch : s) {

              if (isalnum(ch)) {
                  postfix += ch;
              }
              else if (ch == '(') {
                  st.push(ch);
              }
              else if (ch == ')') {
                  while (!st.empty() && st.top() != '(') {
                      postfix += st.top();
                      st.pop();
                  }
                  if (!st.empty()) st.pop();
              }
              else {
                  while (!st.empty() &&
                        (priority(ch) < priority(st.top()) ||
                        (priority(ch) == priority(st.top()) && ch == '^'))) {
                      postfix += st.top();
                      st.pop();
                  }
                  st.push(ch);
              }
          }

          while (!st.empty()) {
              postfix += st.top();
              st.pop();
          }

          reverse(postfix.begin(), postfix.end());
          return postfix;
      }
  }; 