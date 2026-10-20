#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <random>

using namespace std;

class SumOfSortableInteger {
public:
    int sortableIntegers(vector<int>& nums) {
        int n = nums.size();
        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());

        mt19937_64 rng(1337);
        vector<unsigned long long> val_hash(100001);
        for (int i = 0; i <= 100000; ++i) val_hash[i] = rng();

        vector<unsigned long long> pref_h(n + 1, 0), pref_sh(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            pref_h[i + 1] = pref_h[i] + val_hash[nums[i]];
            pref_sh[i + 1] = pref_sh[i] + val_hash[sorted_nums[i]];
        }

        vector<int> drop_pref(n, 0);
        for (int i = 0; i < n - 1; ++i) {
            drop_pref[i + 1] = drop_pref[i] + (nums[i] > nums[i + 1] ? 1 : 0);
        }

        long long total_sum = 0;
        for (int k = 1; k <= n; ++k) {
            if (n % k == 0) {
                bool ok = true;
                for (int i = 0; i < n; i += k) {
                    if (pref_h[i + k] - pref_h[i] != pref_sh[i + k] - pref_sh[i]) {
                        ok = false;
                        break;
                    }
                    if (k > 1) {
                        int drops = drop_pref[i + k - 1] - drop_pref[i];
                        if (drops > 1 || (drops == 1 && nums[i + k - 1] > nums[i])) {
                            ok = false;
                            break;
                        }
                    }
                }
                if (ok) total_sum += k;
            }
        }
        return (int)total_sum;
    }
};

int main() {
    SumOfSortableInteger ssi;
    vector<int> nums = {3, 1, 2};
    cout << "Sum: " << ssi.sortableIntegers(nums) << endl;
}