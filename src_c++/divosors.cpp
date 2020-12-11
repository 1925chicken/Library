set<u64> enum_divisors(u64 n){
    set<u64> res;
    for(u64 i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            res.insert(i);
            if(n / i != i)
                res.insert(n / i);
        }
    }
    return res;
}

vector<u64> enum_divisors(u64 N) {
    vector<u64> res;
    for (u64 i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

vector<P> factrize(u64 n)
{
    vector<pair<u64, u64>> res;
    for (u64 i = 2; i <= sqrtl(n); i++)
    {
        u64 k = i;
        u64 cnt = 0;
        while (n % k == 0)
        {
            n /= k;
            cnt++;
        }
        res.emplace_back(k, cnt);
    }
    if (n != 1)
    {
        res.emplace_back(n, 1);
    }
    return res;
}
set<u64> factrize(u64 n)
{
    set<u64> res;
    for (u64 i = 2; i <= sqrtl(n); i++)
    {
        u64 k = i;
        u64 cnt = 0;
        while (n % k == 0)
        {
            n /= k;
            res.insert(k);
        }
    }
    if (n != 1)
    {
        res.insert(n);
    }
    return res;
}

