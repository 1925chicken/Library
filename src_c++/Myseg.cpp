/*
  i32 -> int_fast32_t
  i64 -> int_fast64_t
  u32 -> uint_fast32_t
  u64 -> uint_fast64_t
  usize -> size_t
 */
template<typename T>
T e(){
    return (u64)(2147483647);
}
template<typename T>
T op(T a,T b) {
    return min(a,b);
}
template<class T,T (*op)(T,T),T (*e)()>
class segtree{
private:
    vec<T> node;
    u32 cnt = 0;
    usize sz;
    usize n;
    void update(usize k){
        node[k] = op(node[2 * k],node[2 * k + 1]);
    }
public:
    segtree():segtree(0){}
    segtree(usize n): segtree(vec<T>(n,e())){}
    segtree(const vec<T> &a): n((u64)(a.size())){
        while(((u64)(1) << cnt) < n){
            cnt++;
        }
        sz = ((u64)(1) << cnt);
        node = vec<T>(2 * sz,e());
        rep(i,n){
            node[sz + i] = a[i];
        }
        for(u32 i = sz - 1; 1 <= i; i--){
            update(i);
        }
    }
    void set(u64 i,T x){
        i += sz;
        node[i] = x;
        for(u32 a = 1;a <= cnt; a++)update(i >> a);
    }
    T get(u64 i){
        return node[i + sz];
    }
    T prod(u64 l,u64 r){
        T resl = e();
        l += sz;
        r += sz;
        T resr = e();
        while(l < r){
            if(l & 1)resl = op(resl,node[l++]);
            if(r & 1)resr = op(resr,node[--r]);
            l >>= 1;
            r >>= 1;
        }
        return op(resl,resr);
    }
    T all_prod(){
        return node[1];
    }
};