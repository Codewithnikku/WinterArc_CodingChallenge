#include <iostream>
#include <vector>
#include <string>
using namespace std;

class PalindromicPathQueriesInTree {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        vector<int> parent(n, -1), depth(n, 0);
        vector<int> order = {0};
        for (int i = 0; i < (int)order.size(); ++i) {
            int u = order[i];
            for (int v : adj[u]) {
                if (v == parent[u]) continue;
                parent[v] = u;
                depth[v] = depth[u] + 1;
                order.push_back(v);
            }
        }

        int LOG = 1;
        while ((1 << LOG) <= n) ++LOG;
        vector<vector<int>> up(LOG, vector<int>(n));
        for (int i = 0; i < n; ++i) up[0][i] = (parent[i] == -1 ? i : parent[i]);

        for (int k = 1; k < LOG; ++k)
            for (int i = 0; i < n; ++i)
                up[k][i] = up[k - 1][up[k - 1][i]];

        auto lca = [&](int u, int v) {
            if (depth[u] < depth[v]) swap(u, v);
            int diff = depth[u] - depth[v];
            for (int k = 0; k < LOG; ++k)
                if (diff & (1 << k)) u = up[k][u];

            if (u == v) return u;

            for (int k = LOG - 1; k >= 0; --k) {
                if (up[k][u] != up[k][v]) {
                    u = up[k][u];
                    v = up[k][v];
                }
            }
            return parent[u];
        };

        vector<int> tin(n), tout(n);
        vector<int> euler(n);
        int timer = 0;
        vector<pair<int, int>> st = {{0, 0}};

        while (!st.empty()) {
            auto& [u, state] = st.back();
            if (state == 0) {
                tin[u] = timer;
                euler[timer++] = u;
                state = 1;
            } else if (state <= (int)adj[u].size()) {
                int v = adj[u][state - 1];
                ++state;
                if (v == parent[u]) continue;
                st.push_back({v, 0});
            } else {
                tout[u] = timer - 1;
                st.pop_back();
            }
        }

        vector<int> bit(n + 1, 0);
        auto add = [&](int i, int val) {
            for (++i; i <= n; i += i & -i) bit[i] ^= val;
        };
        auto pref = [&](int i) {
            int res = 0;
            for (++i; i > 0; i -= i & -i) res ^= bit[i];
            return res;
        };

        for (int u = 0; u < n; ++u) {
            int mask = 1 << (s[u] - 'a');
            add(tin[u], mask);
            if (tout[u] + 1 < n) add(tout[u] + 1, mask);
        }

        auto rootMask = [&](int u) {
            return pref(tin[u]);
        };

        vector<bool> ans;
        for (auto& q : queries) {
            if (q[0] == 'u') {
                int u = 7;
                while (u < (int)q.size() && q[u] == ' ') ++u;
                int node = 0;
                while (u < (int)q.size() && isdigit(q[u])) node = node * 10 + q[u++] - '0';
                while (u < (int)q.size() && q[u] == ' ') ++u;
                char c = q[u];

                if (s[node] != c) {
                    int change = (1 << (s[node] - 'a')) ^ (1 << (c - 'a'));
                    add(tin[node], change);
                    if (tout[node] + 1 < n) add(tout[node] + 1, change);
                    s[node] = c;
                }
            } else {
                int u = 6;
                while (u < (int)q.size() && q[u] == ' ') ++u;
                int a = 0, b = 0;
                while (u < (int)q.size() && isdigit(q[u])) a = a * 10 + q[u++] - '0';
                while (u < (int)q.size() && q[u] == ' ') ++u;
                while (u < (int)q.size() && isdigit(q[u])) b = b * 10 + q[u++] - '0';

                int w = lca(a, b);
                int mask = rootMask(a) ^ rootMask(b) ^ (1 << (s[w] - 'a'));
                ans.push_back((mask & (mask - 1)) == 0);
            }
        }

        return ans;
    }
};

int main() {
    int n = 3;
    string s = "aac";
    vector<vector<int>> edges = {{0,1}, {1,2}};
    vector<vector<string>> queries = {{"query 0 2"},{"update 1 b"},{"query 0 2"}};
    PalindromicPathQueriesInTree ppqit;
    return 0;
}