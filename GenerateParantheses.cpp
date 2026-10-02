#include <iostream>
#include <vector>
#include <string>
using namespace std;



class GenerateParantheses {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> genParans;
        generateParans(genParans, "", 0, 0, n);
        
        return genParans;
    }

private:
    void generateParans(vector<string>& genParans, string current, int open, int close, int max) {
        if(current.length() == max * 2)  { genParans.push_back(current); return; }
        if(open < max) { generateParans(genParans, current + '(', open+1, close, max ); }
        if(close < open) { generateParans(genParans, current + ')', open, close+1, max ); }
    }
};

int main() {
    GenerateParantheses gp;
    int n = 3;
    vector<string> parans = gp.generateParenthesis(n);
    cout << "Generated Parantheses: " << endl;
    for(const string &p : parans) {
        cout << p << endl;
    }
    return 0;
}