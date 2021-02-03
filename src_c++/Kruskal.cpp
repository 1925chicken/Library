template <typename T>
class UnionFind
{
public:
    vector<T> par;
    UnionFind(T n) : par(n, -1) {}
    void init(T n)
    {
        for (usize i = 0; i < n; i++)
        {
            par[i] = -1;
        }
    }

    i64 root(T x)
    {
        if (par[x] < 0)
            return x;
        else
            return par[x] = root(par[x]);
    }

    bool same(T x, T y)
    {
        return root(x) == root(y);
    }

    bool merge(T x, T y)
    {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (par[x] > par[y])
            swap(x, y);
        par[x] += par[y];
        par[y] = x;
        return true;
    }

    i64 size(T x)
    {
        return -par[root(x)];
    }
};

template<typename T>
class edge{
public:
    T from,to,cost;
};

template<typename T>
T kruskal(vector<edge<T>> &edges,i64 V){
    sort(edges.begin(),edges.end(),[](const edge<T> &a,const edge<T> &b){
        return a.cost < b.cost;
    });
    UnionFind uft(V);
    T res = 0;
    for(edge<T> &e : edges){
        if(!(uft.same(e.from,e.to))){
            uft.merge(e.from,e.to);
            res += e.cost;
        }
    }
    return res;
}
