#include <stack>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string preToInfix(string pre_exp) {
        stack<string> st;
        reverse(pre_exp.begin(), pre_exp.end());

        for(int i = 0; i < pre_exp.length(); i++) {
            char c = pre_exp[i];

            if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
                st.push(string(1, c));
            } else {
                string op1 = st.top(); st.pop();
                string op2 = st.top(); st.pop();
                string temp = "(" + op1 + c + op2 + ")";
                st.push(temp);
            }
        }

        return st.top();
    }
};
