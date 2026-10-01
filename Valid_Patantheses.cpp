#include <iostream>
#include <stack>
using namespace std;

class ValidParantheses {
public:
    bool isValid(string str) {
        stack<char> st;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '(' || str[i] == '[' || str[i] == '{'){
                st.push(str[i]);
            }else {
                if (st.empty()) { return false; }
                if (st.top() == '(' && str[i] == ')' ||
                    st.top() == '{' && str[i] == '}' ||
                    st.top() == '[' && str[i] == ']') {
                    st.pop();
                } else {
                    return false;
                }
            }
        }
        return st.empty();
    }
};

int main() {
    ValidParantheses vp;
    string str = "[{()}]";
    cout << "Is valid: " << (vp.isValid(str) ? "Valid" : "Invalid") << endl;
}