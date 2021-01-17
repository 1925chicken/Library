constexpr i64 MAX = 10000000;
constexpr i64 MOD = 1000000007;
i64 fac[MAX], finv[MAX], inv[MAX];
template <i64 modulus>
class modcal
{

public:
  i64 a;

  constexpr modcal(const i64 x = 0) noexcept : a(x % modulus) {}
  constexpr i64 &value() noexcept { return a; }
  constexpr const i64 &value() const noexcept { return a; }
  constexpr modcal operator+(const modcal rhs) const noexcept
  {
    return modcal(*this) += rhs;
  }
  constexpr modcal operator-(const modcal rhs) const noexcept
  {
    return modcal(*this) -= rhs;
  }
  constexpr modcal operator*(const modcal rhs) const noexcept
  {
    return modcal(*this) *= rhs;
  }
  constexpr modcal operator/(const modcal rhs) noexcept
  {
    return modcal(*this) /= rhs;
  }
  constexpr modcal &operator+=(const modcal rhs) noexcept
  {
    a += rhs.a;
    if (a >= modulus)
    {
      a -= modulus;
    }
    return *this;
  }
  constexpr modcal &operator-=(const modcal rhs) noexcept
  {
    if (a < rhs.a)
    {
      a += modulus;
    }
    a -= rhs.a;
    return *this;
  }
  constexpr modcal &operator*=(const modcal rhs) noexcept
  {
    a = a * rhs.a % modulus;
    return *this;
  }
  constexpr modcal &operator/=(modcal rhs) noexcept
  {
    i64 exp = modulus - 2;
    while (exp)
    {
      if (exp % 2)
      {
        *this *= rhs;
      }
      rhs *= rhs;
      exp /= 2;
    }
    return *this;
  }

  void COMninit()
  {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++)
    {
      fac[i] = fac[i - 1] * i % modulus;
      inv[i] = MOD - inv[modulus % i] * (modulus / i) % modulus;
      finv[i] = finv[i - 1] * inv[i] % modulus;
    }
  }
  i64 COMn(i64 n, i64 k)
  {
    if (n < k)
      return 0;
    if (n < 0 || k < 0)
      return 0;
    return fac[n] * (finv[k] * finv[n - k] % modulus) % modulus;
  }
  constexpr modpow(const modcal<1000000007> &a, i64 n)
  {
    if (n == 0)
      return 1;
    auto t = modpow(a, n / 2);
    t = t * t;
    if (n & 1)
      t = t * a;
    return t;
  }
};
using modc = modcal<1000000007>;