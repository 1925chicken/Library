set<i64> enum_divisors(i64 n){
    set<i64> res;
    for(i64 i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            res.insert(i);
            if(n / i != i)
                res.insert(n / i);
        }
    }
    return res;
}

vector<i64> enum_divisors(i64 N) {
    vector<i64> res;
    for (i64 i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

vector<pair<i64,i64>> factrize(i64 n)
{
    vector<pair<i64, i64>> res;
    for (i64 i = 2; i <= sqrtl(n); i++)
    {
        i64 k = i;
        i64 cnt = 0;
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
set<i64> factrize(i64 n)
{
    set<i64> res;
    for (i64 i = 2; i <= sqrtl(n); i++)
    {
        i64 k = i;
        i64 cnt = 0;
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

