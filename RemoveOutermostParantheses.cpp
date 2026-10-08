#include<iostream>
#include<string>
using namespace std;

class RemoveOuterMostParantheses {
public:
    string removeOuterParentheses(string s) {
        int cnt = 0;
        string res = "";

        for (char c : s) {
            if (c == '(') {
                if (cnt > 0) { res += c; }
                cnt++;
            } else if (c == ')') {
                cnt--;
                if (cnt > 0) { res += c; }
            }
        }

        return res;
    }
};

int main() {
    RemoveOuterMostParantheses rop;
    string s = "(()())(())";
    cout << rop.removeOuterParentheses(s) << endl;
    return 0;
}