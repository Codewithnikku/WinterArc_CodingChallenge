#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class RemoveInvalidParantheses {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        unordered_set<string> vis;
        queue<string> q;
        q.push(s);
        vis.insert(s);
        bool found = false;

        while (!q.empty()) {
            string cur = q.front();
            q.pop();

            int bal = 0;
            bool valid = true;

            for (char c : cur) {
                if (c == '(') bal++;
                else if (c == ')') {
                    if (--bal < 0) {
                        valid = false;
                        break;
                    }
                }
            }

            if (valid && bal == 0) {
                ans.push_back(cur);
                found = true;
            }

            if (found) continue;

            for (int i = 0; i < (int)cur.size(); i++) {
                if (cur[i] != '(' && cur[i] != ')') continue;

                string next = cur.substr(0, i) + cur.substr(i + 1);
                if (vis.insert(next).second)
                    q.push(next);
            }
        }

        return ans;
    }
};

int main() {
    RemoveInvalidParantheses rip;
    string s = "()())()";
    vector<string> result = rip.removeInvalidParentheses(s);

    cout << "Valid strings after removing invalid parentheses:\n";
    for (const string& str : result) {
        cout << str << endl;
    }

    return 0;
}