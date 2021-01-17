class Lowlink{
int_fast64_t k = 0;
int_fast64_t n;
public:
    std::vector<std::vector<int_fast64_t>> list;
    std::vector<std::vector<bool>> used_e;
    std::vector<int_fast64_t> ord,lowlink;
    std::vector<std::pair<int_fast64_t,int_fast64_t>> bridge;//橋
    std::vector<int_fast64_t>art;//関節点
    std::vector<int_fast64_t> used_v;
    Lowlink(std::vector<std::pair<int_fast64_t ,int_fast64_t>> &g,bool direction,int_fast64_t v):n(v){//directon = 1なら有向グラフ
        list.resize(n);
        used_v.resize(n,false);
        used_e.resize(n,std::vector<bool>(n,false));
        ord.resize(n),lowlink.resize(n);
        for(auto [from,to]:g){
            list[from].emplace_back(to);
            if(!direction)list[to].emplace_back(from);
        }
    }
    void dfs(int_fast64_t par,int_fast64_t now){
            used_v[now] = 1;
            ord[now] = lowlink[now] = k++;
            int_fast64_t cnt = 0;
            bool Art = false;
            for(auto v:list[now]){
                if(!used_v[v]){
                    used_e[now][v] = 1;
                    cnt++;
                    dfs(now,v);
                    lowlink[now] = min(lowlink[now],lowlink[v]);
                    if(par != -1 && ord[now] <= lowlink[v])Art = 1;
                    if(ord[now] < lowlink[v])bridge.emplace_back(make_pair(min(now,v),max(now,v)));
                }else if(!used_e[v][now]){//このとき(now,list[now][i])は後退辺
                    lowlink[now] = min(lowlink[now],ord[v]);
                }
            }
            if(par == -1 && cnt >= 2)Art = true;
            if(Art)art.emplace_back(now);
    }
};