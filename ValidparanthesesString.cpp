#include<iostream>
#include<string>
using namespace std;

class ValidParanthesesString {
public:
    bool checkValidString(string s) {
        int minOpen = 0, maxOpen = 0;

        for (char c : s) {
            if (c == '(') { minOpen++; maxOpen++; } 
            else if (c == ')') { minOpen--; maxOpen--; } 
            else { minOpen--; maxOpen++; }

            if (maxOpen < 0) return false;
            minOpen = max(0, minOpen);
        }

        return minOpen == 0;
    }
};

int main() {
    ValidParanthesesString vps;
    string s = "()";
    cout << vps.checkValidString(s) << endl;
    return 0;
}