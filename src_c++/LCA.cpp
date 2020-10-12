template<typename T>
class LCA {
public:
    vector<int_fast32_t> depth;
    const int_fast32_t dig;
    const T &g;
    vector<vector<int_fast32_t>> doubling;

    LCA(const T &g) : g(g), depth(g.size()), dig(64) {
        doubling.assign(dig, vector<int_fast32_t>(g.size(), -1));
    }

    void dfs(int_fast32_t now, int_fast32_t par, int_fast32_t d) {
        doubling[0][now] = par;
        depth[now] = d;
        for (auto &v: g[now]) {
            if (v != par)dfs(v, now, d + 1);
        }
    }

    void construct() {
        dfs(0, -1, 0);
        for (int_fast32_t i = 0; i < dig - 1; i++) {
            for (int_fast32_t j = 0; j < doubling[i].size(); j++) {
                if (doubling[i][j] == -1)doubling[i + 1][j] = -1;
                else doubling[i + 1][j] = doubling[i][doubling[i][j]];
            }
        }
    }

    int_fast32_t query_answer(int_fast32_t u, int_fast32_t v) {
        if (depth[u] > depth[v])swap(u, v);
        for(int_fast32_t i = dig - 1; 0 <= i; i--){
            if(((depth[v] - depth[u]) >> i) & 1) v = doubling[i][v];
        }
        if(u == v) return u;
        for (int_fast32_t i = dig - 1; 0 <= i; --i) {
            if (doubling[i][u] != doubling[i][v]) {
                u = doubling[i][u];
                v = doubling[i][v];
            }
        }
        return doubling[0][u];
    }
};