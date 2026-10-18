#include <iostream>
#include <vector>
using namespace std;

class NumberOfWaysToReorderArrayToGetSameBST {
    long long MOD = 1e9 + 7;
    vector<vector<long long>> table;

public:
    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        table.assign(n, vector<long long>(n, 0));
        for (int i = 0; i < n; ++i) {
            table[i][0] = 1;
            for (int j = 1; j <= i; ++j) {
                table[i][j] = (table[i - 1][j - 1] + table[i - 1][j]) % MOD;
            }
        }

        return (solve(nums) - 1 + MOD) % MOD;
    }

private:
    long long solve(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return 1;

        vector<int> left, right;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        long long leftWays = solve(left);
        long long rightWays = solve(right);

        return (((leftWays * rightWays) % MOD) * table[n - 1][left.size()]) % MOD;
    }
};


int main(){
    NumberOfWaysToReorderArrayToGetSameBST nwrags_bst;
    vector<int> nums1 = {2, 1, 3};
    vector<int> nums2 = {3, 4, 5, 1, 2};
    vector<int> nums3 = {1, 2, 3};
    
    cout << "Example 1 Output: " << nwrags_bst.numOfWays(nums1) << endl;
    cout << "Example 2 Output: " << nwrags_bst.numOfWays(nums2) << endl;
    cout << "Example 3 Output: " << nwrags_bst.numOfWays(nums3) << endl;
    
    return 0;
}