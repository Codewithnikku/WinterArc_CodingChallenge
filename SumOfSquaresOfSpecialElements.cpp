#include <iostream>
#include <vector>
using namespace std;

class SumOfSquaresOfSpecialElements {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;

        for (int i = 0; i < n; ++i) {
            if (n % (i + 1) == 0) {
                sum += nums[i] * nums[i];
            }
        }

        return sum;
    }
};

int main() {
    SumOfSquaresOfSpecialElements ssse;
    vector<int> nums = {1, 2, 3, 4};
    cout << ssse.sumOfSquares(nums) << endl; 
    return 0;
}