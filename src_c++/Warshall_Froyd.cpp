#include<cstdint>
#include<algorithm>
void warshall_froyd(std::vector<std::vector<int_fast64_t>> dist){//隣接行列を使う
    i64 n = dist.size();
    for(int_fast32_t k = 0; k < n; k++){
        for(int_fast32_t i = 0; i < n; i++){
            for(int_fast32_t j = 0; j < n; j++){
                dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
            }
        }
    }
}
bool negative_cycle(std::vector<std::vector<int_fast64_t>> &dist){
    i64 n = dist.size();
    for(int_fast32_t i = 0; i < n; i++){
        if(dist[i][i] < 0)return true;
    }
    return false;
}