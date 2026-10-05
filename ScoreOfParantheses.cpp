#include <iostream>
#include <string>
using namespace std;

class ScoreOfParentheses {
public:
    int scoreOfParentheses(string s) {
        int score = 0; int balance = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                balance++;
            } else {
                balance--;
                if (s[i - 1] == '(') {
                    score += 1 << balance;
                }
            }
        }
        return score;
    }
};

int main() {
    ScoreOfParentheses sop;
    string s = "(())";
    int score = sop.scoreOfParentheses(s);
    cout << "Score of parentheses: " << score << endl;
    return 0;
}