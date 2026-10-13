#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<long long> sq(n);
        long long total = 0;
        for (int i = 0; i < n; i++) {
            sq[i] = 1LL * nums[i] * nums[i];
            total += sq[i];
        }

        int k = n / 2; 
        nth_element(sq.begin(), sq.begin() + k, sq.end());

        long long small = 0;
        for (int i = 0; i < k; i++) small += sq[i];

        return total - 2 * small;
    }
};

using MaximumAlternatingSumOfSquares = Solution;

int main() {
    MaximumAlternatingSumOfSquares mass;
    vector<int> nums = {1, 2, 3};
    cout << mass.maxAlternatingSum(nums) << endl;
    return 0;
}