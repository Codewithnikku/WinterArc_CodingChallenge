#include <iostream>
#include <vector>
#include <utility>
using namespace std;

class CountIslandsWithTotalValueDivisibleByK {
public:
    int countIslands(vector<vector<int>>& grid, int k) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));
        int count = 0;
        const int dr[] = {-1, 1, 0, 0};
        const int dc[] = {0, 0, -1, 1};

        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 0 || visited[r][c]) {
                    continue;
                }

                long long total = 0;
                vector<pair<int, int>> stack{{r, c}};
                visited[r][c] = true;

                while (!stack.empty()) {
                    int row = stack.back().first;
                    int col = stack.back().second;
                    stack.pop_back();
                    total += grid[row][col];

                    for (int direction = 0; direction < 4; ++direction) {
                        int nextRow = row + dr[direction];
                        int nextCol = col + dc[direction];
                        if (nextRow >= 0 && nextRow < rows &&
                            nextCol >= 0 && nextCol < cols &&
                            grid[nextRow][nextCol] != 0 &&
                            !visited[nextRow][nextCol]) {
                            visited[nextRow][nextCol] = true;
                            stack.emplace_back(nextRow, nextCol);
                        }
                    }
                }

                if (total % k == 0) {
                    ++count;
                }
            }
        }

        return count;
    }
};

int main() {
    CountIslandsWithTotalValueDivisibleByK ciwtvdbk;
    int k = 5;
    vector<vector<int>> grid = {
        {0, 2, 1, 0, 0},
        {0, 5, 0, 0, 5},
        {0, 0, 1, 0, 0},
        {0, 1, 4, 7, 0},
        {0, 2, 0, 0, 8}
    };
    cout << "Islands Count: " << ciwtvdbk.countIslands(grid, k) << endl;
    return 0;
}