#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class ApplyOperationsOnArrayToMaximizeSumOfSquares {
public:
    int maxSum(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int cnt[31] = {};

        for (int x : nums) {
            for (int b = 0; b < 31; b++) {
                cnt[b] += (x >> b) & 1;
            }
        }

        long long ans = 0;
        while (k--) {
            long long x = 0;

            for (int b = 0; b < 31; b++) {
                if (cnt[b] > 0) { x |= 1LL << b; cnt[b]--; }
            }
            ans = (ans + x * x) % MOD;
        }

        return ans;
    }
};

int main() {
    ApplyOperationsOnArrayToMaximizeSumOfSquares aoamss;
    vector<int> nums = {2, 6, 5, 8}; int k = 2;
    cout << "Max Sum of Squares: " << aoamss.maxSum(nums, k) << endl;
}