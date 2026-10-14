#include<iostream>
#include<string>
using namespace std;

class MaximizeSumOfSquaresOfDigits {
public:
    string maxSumOfSquares(int num, int sum) {
        if (sum > 9 * num) return "";

        string ans(num, '0');

        for (int i = 0; i < num && sum > 0; i++) {
            int digit = min(9, sum);
            ans[i] += digit;
            sum -= digit;
        }

        if (sum > 0) return "";
        return ans;
    }
};

int main() {
    MaximizeSumOfSquaresOfDigits mssd;
    int num = 2; int sum = 3;
    cout << "Output: " << mssd.maxSumOfSquares(num, sum) << endl;
}