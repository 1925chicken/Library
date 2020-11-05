#include<cstdint>
#include<vector>
std::vector<int_fast32_t> prime;//実際に素数を小さい方から格納する配列。
int_fast32_t sieve_cnt(int_fast32_t n){
    //n以下の整数に素数が何個あるかを返します。
    std::vector<bool> is_prime(n + 1,true);//この配列でtrueになっているindexの整数は素数。
    is_prime[0] = is_prime[1] = 0;
    for(int_fast32_t i = 2; i <= n; i++){
        if(is_prime[i]){
            prime.emplace_back(i);
            for(int_fast32_t j = 2 * i; j <= n; j+= i){
                is_prime[j] = false;
            }
        }
    }
    return prime.size();
}

std::vector<bool> sieve(int32_t n){
    //ふるい自体を返します。
    std::vector<bool> is_prime(n + 1,true);//この配列でtrueになっているindexの整数は素数。
    is_prime[0] = is_prime[1] = 0;
    for(int_fast32_t i = 2; i <= n; i++){
        if(is_prime[i]){
            prime.emplace_back(i);
            for(int_fast32_t j = 2 * i; j <= n; j+= i){
                is_prime[j] = false;
            }
        }
    }
    return is_prime;
}

//区間篩はまた今度。
