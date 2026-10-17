#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

class MinimumSwapsToSortByDigitSum {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> arr(n);

        for (int i = 0; i < n; i++) {
            int x = nums[i], sum = 0;
            while (x > 0) {
                sum += x % 10;
                x /= 10;
            }
            arr[i] = {sum, nums[i]};
        }

        sort(arr.begin(), arr.end());

        unordered_map<int, int> pos;
        for (int i = 0; i < n; i++) {
            pos[nums[i]] = i;
        }

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {
            if (visited[i] || pos[arr[i].second] == i)
                continue;

            int cycle = 0, j = i;

            while (!visited[j]) {
                visited[j] = true;
                j = pos[arr[j].second];
                cycle++;
            }

            swaps += cycle - 1;
        }

        return swaps;
    }
};

int main(){
    MinimumSwapsToSortByDigitSum mstsbds;
    vector<int> nums = {37, 100};
    cout << "Output: " << mstsbds.minSwaps(nums) << endl; //  output: 1
    return 0;
}