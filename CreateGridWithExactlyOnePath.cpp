#include <iostream>
#include <vector>
using namespace std;

class CreateGridWithExactlyOnePath {
public:
    vector<string> createGrid(int m, int n) {
        vector<string>grid(m,string(n,'#'));

        for(int i=0;i<n;i++){
            grid[0][i]='.';
        }
        for(int j=0;j<m;j++){
            grid[j][n-1]='.';
        }
        return grid;
    }
};


int main() {
    CreateGridWithExactlyOnePath cgweop;
    int m = 1; int n = 4;
    cout << "Grid:" << endl;
    for (const string& row : cgweop.createGrid(m, n)) {
        cout << row << endl;
    }
    return 0;
}