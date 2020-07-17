set<ll> enum_divisors(ll n){
    set<ll> res;
    for(ll i = 1; i <= sqrt(n); i++){
        if(n % i == 0){
            res.insert(i);
            if(n / i != i)
                res.insert(n / i);
        }
    }
    return res;
}

vector<ll> enum_divisors(ll N) {
    vector<ll> res;
    for (ll i = 1; i * i <= N; ++i) {
        if (N % i == 0) {
            res.push_back(i);
            if (N/i != i) res.push_back(N/i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

vector<pair<ll, ll>> factrize(ll n)
{
    vector<pair<ll, ll>> res;
    for (ll i = 2; i <= sqrtl(n); i++)
    {
        ll k = i;
        ll cnt = 0;
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
set<ll> factrize(ll n)
{
    set<ll> res;
    for (ll i = 2; i <= sqrtl(n); i++)
    {
        ll k = i;
        ll cnt = 0;
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

