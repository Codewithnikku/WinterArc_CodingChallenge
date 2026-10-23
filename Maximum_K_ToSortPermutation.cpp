#include <iostream>
#include <vector>
using namespace std;

class Maximum_K_ToSortPermutation {
public:
    int sortPermutation(vector<int>& nums) {
        int n = nums.size();
        int k = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] != i) {
                k = (k == -1) ? nums[i] & i : k & nums[i] & i;
            }
        }

        return max(k, 0);
    }
};

int main() {
    Maximum_K_ToSortPermutation mksp;
    vector<int> nums = {0, 3, 2, 1};
    cout << "maximum K: " << mksp.sortPermutation(nums) << endl;
}