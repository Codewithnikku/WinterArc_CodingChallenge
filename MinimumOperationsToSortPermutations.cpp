#include <iostream>
#include <vector>
#include <queue>
using namespace std;


class MinimumOperationsToSortPermutations {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        if (n <= 1) return 0;

        vector<int> starts;
        
        bool is_s = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(i + 1) % n] != (nums[i] + 1) % n) {
                is_s = false;
                break;
            }
        }
        if (is_s) starts.push_back(nums[0]);

        bool is_r = true;
        for (int i = 0; i < n; ++i) {
            if (nums[(i + 1) % n] != (nums[i] - 1 + n) % n) {
                is_r = false;
                break;
            }
        }
        if (is_r) starts.push_back(n + nums[0]);

        if (starts.empty()) return -1;

        queue<int> q;
        vector<int> dist(2 * n, -1);
        for (int s : starts) {
            if (s == 0) return 0;
            dist[s] = 0;
            q.push(s);
        }

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            int next_l, next_rev;
            if (u < n) {
                next_l = (u + 1) % n;
                next_rev = n + (u - 1 + n) % n;
            } else {
                int i = u - n;
                next_l = n + (i - 1 + n) % n;
                next_rev = (i + 1) % n;
            }

            if (next_l == 0) return dist[u] + 1;
            if (dist[next_l] == -1) {
                dist[next_l] = dist[u] + 1;
                q.push(next_l);
            }

            if (next_rev == 0) return dist[u] + 1;
            if (dist[next_rev] == -1) {
                dist[next_rev] = dist[u] + 1;
                q.push(next_rev);
            }
        }

        return -1;
    }
};

int main(){
    MinimumOperationsToSortPermutations mosp;
    vector<int> nums = {2, 0, 1, 3}; // -1
    cout << "Min. Operations: " << mosp.minOperations(nums) << endl;
    return 0;
}