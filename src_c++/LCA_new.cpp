//
// Created by chicken1925 on 2021/01/22.
//

template<typename T>
class LCA {
public:
    vector<int_fast32_t> depth;
    const int_fast32_t dig;
    vector<vector<int_fast32_t>> g;
    vector<vector<int_fast32_t>> cost;
    vector<int_fast32_t> costs;
    int_fast32_t n;
    vector<vector<int_fast32_t>> doubling;

    LCA(int_fast64_t _n) : n(_n),dig(64){
        doubling.assign(dig, vector<int_fast32_t>(n, -1));
        costs.resize(n);
        depth.resize(n);
        g.resize(n);
        cost.resize(n);
    }

    void addedge(int_fast32_t u, int_fast32_t v, int_fast32_t c = 0) {
        g[u].emplace_back(v);
        cost[u].emplace_back(c);
        g[v].emplace_back(u);
        cost[v].emplace_back(c);

    }

    void dfs(int_fast32_t now, int_fast32_t par = -1, int_fast32_t d = 0, int_fast32_t c = 0) {
        doubling[0][now] = par;
        depth[now] = d;
        costs[now] = c;
        rep(i, len(g[now])) {
            if (g[now][i] != par)dfs(g[now][i], now, d + 1, c + cost[now][i]);
        }
    }

    void construct() {
        dfs(0);
        for (int_fast32_t i = 0; i < dig - 1; i++) {
            for (int_fast32_t j = 0; j < doubling[i].size(); j++) {
                if (doubling[i][j] == -1)doubling[i + 1][j] = -1;
                else doubling[i + 1][j] = doubling[i][doubling[i][j]];
            }
        }
    }

    int_fast32_t query_answer(int_fast32_t u, int_fast32_t v) {
        if (depth[u] > depth[v])swap(u, v);
        for (int_fast32_t i = dig - 1; 0 <= i; i--) {
            if (((depth[v] - depth[u]) >> i) & 1) v = doubling[i][v];
        }
        if (u == v) return u;
        for (int_fast32_t i = dig - 1; 0 <= i; --i) {
            if (doubling[i][u] != doubling[i][v]) {
                u = doubling[i][u];
                v = doubling[i][v];
            }
        }
        return doubling[0][u];
    }

    int_fast32_t length(int_fast32_t u, int_fast32_t v) {
        return depth[u] + depth[v] - 2 * depth[query_answer(u, v)];
    }

    int_fast32_t dist(int_fast32_t u, int_fast32_t v) {
        return costs[u] + costs[v] - 2 * costs[query_answer(u, v)];
    }

    bool isOnPath(int_fast32_t u, int_fast32_t v, int_fast32_t x) {
        return length(u, x) + length(v, x) == length(u, v);
    }
};