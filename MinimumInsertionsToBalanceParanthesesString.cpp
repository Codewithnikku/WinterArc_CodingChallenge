#include <iostream>
using namespace std;

class MinimumInsertionsToBalanceParanthesesString {
public:
    int minInsertions(string s) {
        int open = 0;
        int close = 0;
        for (char c : s) {
            const bool isOpen = c == '(';
            open += (isOpen << 1) - (!isOpen);
            const bool openOdd = open & 1;
            const bool openNeg = open < 0;
            close += (isOpen & openOdd) + (!isOpen & openNeg);
            open += -(isOpen & openOdd) + ((!isOpen & openNeg) << 1);
        }
        return open + close;
    }
};

int main(){
    MinimumInsertionsToBalanceParanthesesString mitbps;
    string s = "(()))";
    cout << "Minum insertions: " << mitbps.minInsertions(s) << endl;
    return 0;
}