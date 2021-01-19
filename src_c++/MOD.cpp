constexpr i64 MOD = 1000000007;


template<i64 modulus>
class modcal {
public:
    i64 a;

    constexpr modcal(const i64 x = 0) noexcept: a(x % modulus) {}

    constexpr i64 &value() noexcept { return a; }

    constexpr const i64 &value() const noexcept { return a; }

    constexpr modcal operator+(const modcal rhs) const noexcept {
        return modcal(*this) += rhs;
    }

    constexpr modcal operator-(const modcal rhs) const noexcept {
        return modcal(*this) -= rhs;
    }

    constexpr modcal operator*(const modcal rhs) const noexcept {
        return modcal(*this) *= rhs;
    }

    constexpr modcal operator/(const modcal rhs) noexcept {
        return modcal(*this) /= rhs;
    }

    constexpr modcal &operator+=(const modcal rhs) noexcept {
        a += rhs.a;
        if (a >= modulus) {
            a -= modulus;
        }
        return *this;
    }

    constexpr modcal &operator-=(const modcal rhs) noexcept {
        if (a < rhs.a) {
            a += modulus;
        }
        a -= rhs.a;
        return *this;
    }

    constexpr modcal &operator*=(const modcal rhs) noexcept {
        a = a * rhs.a % modulus;
        return *this;
    }

    constexpr modcal &operator/=(modcal rhs) noexcept {
        i64 exp = modulus - 2;
        while (exp) {
            if (exp % 2) {
                *this *= rhs;
            }
            rhs *= rhs;
            exp /= 2;
        }
        return *this;
    }

    constexpr modcal<MOD> modpow(const modcal<MOD> &a, i64 n) {
        if (n == 0)
            return 1;
        auto t = modpow(a, n / 2);
        t = t * t;
        if (n & 1)
            t = t * a;
        return t;
    }

};

using modc = modcal<MOD>;

class com {
    vector <modc> fac, inv;
    i64 n;
public:
    com(i64 N) : fac(N + 1), inv(N + 1), n(N) {
        fac[0] = 1;
        for (i64 i = 1; i <= n; i++)fac[i] = fac[i - 1] * i;
        inv[n] = fac[n].modpow(fac[n], MOD - 2);
        for (i64 i = n; i >= 1; i--)inv[i - 1] = inv[i] * i;

    }

    modc combination(i64 n, i64 k) {
        if (k < 0 || k > n)return 0;
        return fac[n] * inv[k] * inv[n - k];
    }

    modc permutation(i64 n, i64 k) {
        if (k < 0 || k > n)return 0;
        return combination(n, k) * fac[k];
    }
};
