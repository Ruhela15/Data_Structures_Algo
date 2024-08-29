#include <iostream>
#include <stack>
using namespace std;

class Solution {
  public:
    string preToPost(string pre_exp) {
        stack<string> st;
        int n = pre_exp.size();
        
        for (int i = n - 1; i >= 0; i--) {
            if (pre_exp[i] == '+' || pre_exp[i] == '-' || pre_exp[i] == '*' || pre_exp[i] == '/') {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string post_exp = op1 + op2 + pre_exp[i];
                st.push(post_exp);
            } else {
                st.push(string(1, pre_exp[i]));
            }
        }
        
        return st.top();
    }
};

int main() {
    Solution solution;
    string prefix = "*+AB-CD";
    cout << "Postfix: " << solution.preToPost(prefix) << endl;
    return 0;
}
