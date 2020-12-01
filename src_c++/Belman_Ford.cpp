constexpr i64 INF = 1e18;
class edge {
public:
    i64 from, to, cost;
};

template<typename T>
class Belman_Ford {
public:
    vec<edge> G;
    vec<i64> dist;
    bool flag;
    vec<bool> negative;

    Belman_Ford(const T &v, const T &e) {//vは頂点の数、eは辺の数
        G.resize(e);
        dist.resize(v, INF);
        negative.resize(v, false);
    }

    void init(i64 loop, bool zero) {//グラフの初期化(入力),zeroはゼロスタートかどうか
        rep(i, loop) {
            i64 a, b, c;
            cin >> a >> b >> c;
            edge A = {a - (zero ? 0 : 1), b - (zero ? 0 : 1), c};
            G[i] = A;
        }
    }

    void belman_ford(i64 v, i64 e, i64 s) {
        dist[s] = 0;
        rep(i, v - 1) {
            rep(j, e) {
                if (dist[G[j].from] == INF)continue;
                if (dist[G[j].to] > dist[G[j].from] + G[j].cost)
                    dist[G[j].to] = dist[G[j].from] + G[j].cost;
            }
        }
        rep(i, v) {
            rep(j, e) {
                if (dist[G[j].to] == INF)continue;
                if (dist[G[j].to] > dist[G[j].from] + G[j].cost) {
                    dist[G[j].to] = dist[G[j].from] + G[j].cost;
                    negative[G[j].to] = 1;
                }
                if (negative[G[j].from] == true) {
                    negative[G[j].to] = 1;
                }
            }
        }
    }
};
