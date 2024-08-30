#include <iostream>
#include <stack>
using namespace std;

class Solution {
  public:
    string postToInfix(string exp) {
        stack<string> st;
        for (char ch : exp) {
            if (isalpha(ch)) {
                st.push(string(1, ch));  // Push single character as a string
            } else {
                string op2 = st.top(); st.pop();  // Second operand
                string op1 = st.top(); st.pop();  // First operand
                string infix = "(" + op1 + ch + op2 + ")";
                st.push(infix);
            }
        }
        return st.top();
    }
};

int main() {
    Solution solution;
    string exp;
    
    // Example input
    cout << "Enter postfix expression: ";
    cin >> exp;
    
    // Convert postfix to infix
    string infix = solution.postToInfix(exp);
    cout << "Infix expression: " << infix << endl;
    
    return 0;
}
