#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class FindTargetIndicesAfterSortingArray {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> res;
        for(int i=0; i<n; i++) {
            if(nums[i] == target) res.push_back(i);
        }
        return res;
    }
};

int main(){
    FindTargetIndicesAfterSortingArray ftisa;
    vector<int> nums = {1, 2, 5, 2, 3};
    int target = 2;
    cout << "Target Indices: ";
    for (int index : ftisa.targetIndices(nums, target)) cout << index << " ";
    cout << endl;   
    return 0;
}