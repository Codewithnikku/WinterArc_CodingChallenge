#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

class MinimumSumOfSquaredDifference {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size(), M = 0;
        long long k = 1LL * k1 + k2;
        vector<int> diff(n);

        for (int i = 0; i < n; i++)
            M = max(M, diff[i] = abs(nums1[i] - nums2[i]));

        vector<int> bucket(M + 1);
        for (int x : diff) bucket[x]++;

        for (int i = M; i > 0 && k > 0; i--) {
            int take = min((long long)bucket[i], k);
            bucket[i] -= take;
            bucket[i - 1] += take;
            k -= take;
        }

        long long ans = 0;
        for (int i = 1; i <= M; i++)
            ans += 1LL * bucket[i] * i * i;

        return ans;
    }
};

int main() {
    MinimumSumOfSquaredDifference solver;
    vector<int> nums1 = {1, 4, 10, 12};
    vector<int> nums2 = {5, 8, 6, 9};
    int k1 = 1;
    int k2 = 1;

    cout << solver.minSumSquareDiff(nums1, nums2, k1, k2) << endl; // 43
    return 0;
}