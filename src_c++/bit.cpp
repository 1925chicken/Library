template<class T>
class BIT {
public:
    i64 n;
    vector<i64> seg;
    BIT(i64 n) : N(N){
        seg.resize(N + 1);
        fill_n(begin(seg),N + 1,0);
    }
    void add(i64 i, T x){
        ++i;
        while(i <= N) {
            seg[i] += x;
            i += i & (-i);
        }
    }
    T sum(i64 i) {
        T s = 0;
        while(i > 0) {
            s += seg[i];
            i -= i & (-i);
        }
        return s;
    }
    T sum(i64 a, i64 b) {
        return sum(b) - sum(a);
    }
};