#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <tuple>
#include <climits>
#include <functional>
#include <utility>
using namespace std;

class ShortestPathWithAtMostKConsecutiveIdenticalCharacters {
public:
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges)
            adj[e[0]].push_back({e[1], e[2]});

        using T = tuple<long long, int, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        vector<vector<long long>> dist(n, vector<long long>(k + 1, LLONG_MAX));

        int start = 1;
        dist[0][1] = 0;
        pq.push({0, 0, start});

        while (!pq.empty()) {
            auto [d, u, cnt] = pq.top();
            pq.pop();

            if (d != dist[u][cnt]) continue;
            if (u == n - 1) return (int)d;

            for (auto [v, w] : adj[u]) {
                int nc = (labels[u] == labels[v]) ? cnt + 1 : 1;
                if (nc > k) continue;

                if (d + w < dist[v][nc]) {
                    dist[v][nc] = d + w;
                    pq.push({d + w, v, nc});
                }
            }
        }

        return -1;
    }
};

int main() {
    ShortestPathWithAtMostKConsecutiveIdenticalCharacters spwamkcic;
    int n = 3;
    vector<vector<int>>edges = {
        {0,1,1},
        {1,2,1},
        {0,2,3}
    };
    string labels = "aab";
    int k = 1;
    cout << "Output: " << spwamkcic.shortestPath(n, edges, labels, k) << endl;
}