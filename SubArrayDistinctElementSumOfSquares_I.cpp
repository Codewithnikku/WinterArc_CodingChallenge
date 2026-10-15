#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

class  SubArrayDistinctElementSumOfSquares_I {
public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> st;

            for (int j = i; j < n; j++) {
                st.insert(nums[j]);

                int count = st.size();
                ans += count * count;
            }
        }

        return ans;
    }
};

int main(){
    SubArrayDistinctElementSumOfSquares_I sadess_i;
    vector<int> nums = {1, 2, 1}; 
    cout << "SADE Sum of squares: " << sadess_i.sumCounts(nums) << endl;
    return 0;
}
