template <typename T>
class UnionFind
{
public:
    vector<T> par;
    UnionFind(T n) : par(n, -1) {}
    void init(T n)
    {
        for (i64 i = 0; i < n; i++)
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

