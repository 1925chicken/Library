//based on https://satanic0258.github.io/snippets/tree/EulerTour.html
//verified on https://atcoder.jp/contests/abc138/submissions/19415353
#include<vector>
#include<cstdint>
#include<iostream>

class Euler_Tour {
public:
    std::vector<uint_fast64_t> euler_tour;
    std::vector<uint_fast64_t> begin, end;//[begin, end)の半開区間
    std::vector<uint_fast64_t> depth;
    int_fast64_t n, k;

    Euler_Tour(const std::vector<std::vector<uint_fast64_t>> &g, uint_fast64_t v) : n(g.size()), k(0) {
        begin.resize(n * 2, 0);
        end.resize(n * 2, 0);
        depth.resize(n * 2, 0);
        build(g, v, -1, 0);
    }

    void build(const std::vector<std::vector<uint_fast64_t>> &g, uint_fast64_t v, int_fast64_t par, uint_fast64_t d) {
        begin[v] = k++;
        //depth[k++] = d;
        euler_tour.emplace_back(v);
        for (auto to :g[v]) {
            if (to == par)continue;
            build(g, to, v, d + 1);
            depth[k] = d;
            euler_tour.emplace_back(v);
            k++;
        }
        end[v] = k;
    }
};

