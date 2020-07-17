template <typename T>
T GCD(T x, T y)
{
    if (x < y)
    {
        const T a = x;
        x = y;
        y = a;
    }
    T b = 100000;
    while (b)
    {
        b = x % y;
        x = y;
        y = b;
    }
    return x;
}
template <typename T>
T LCM(T x, T y)
{
    T g = GCD(x, y);
    return x / g * y;
}