#include <iostream>
#include <string>
using namespace std;

class LongestValidParantheses {
public:
    int longestValidParentheses(string s) {
        int maxlen = 0; int left = 0; int right = 0;
        for(char c : s) {
            if(c == '(') { left++; } else { right++; }
            if(left == right) { maxlen = max(maxlen, 2 * right); } 
            else if( right > left) { left = right = 0; }
        }

        left = right = 0;
        for(int i= s.length()-1; i >= 0; --i) {
            if(s[i] == '(') { left++; } else { right++; }
            if(left == right) { maxlen = max(maxlen, 2 * left); }
            else if(left > right) { left = right = 0; }
        }

        return maxlen;
    }
};

int main() {
    LongestValidParantheses lvp;
    string s = ")()())"; cout << lvp.longestValidParentheses(s) << endl;
    return 0;

}