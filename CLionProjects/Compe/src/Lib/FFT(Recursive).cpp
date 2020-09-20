#include<iostream>
#include<vector>
#include<complex>
#include<algorithm>
#include<cmath>
using namespace std;
using i64 = int_fast64_t;
class Fourier_Fast_Transform{
    static void dft(vector<complex<long double>> &com){
        i64 sz = com.size();
        if(sz == 1) return ;
        vector<complex<long double>> a(sz / 2),b(sz / 2);
        for(int i = 0; i < sz / 2; i++){
            a[i] = com[2 * i];
            b[i] = com[2 * i + 1];
        }
        dft(a);
        dft(b);
        complex<long double> now = 1, zeta = polar(1.0,2.0 * acos(-1) / sz);
        for(int i = 0; i < sz / 2; i++){
            com[i] = a[i] + now * b[i];
            com[sz /2  + i] = a[i] - now * b[i];
            now *= zeta;
        }
        return ;
    }
public:
    template<typename T>
    static vector<T> convolve(vector<T> f, vector<T> g){

        i64 sz = 1;
        while(sz < f.size() + g.size()) sz *= 2;
        vector<complex<long double>> nf(sz / 2),ng(sz / 2);
        for(int i = 0; i < f.size(); i++){
            nf[i] = f[i];
            ng[i] = g[i];
        }
        dft(nf);
        dft(ng);
        for(int i = 0; i < sz; i++) nf[i] = conj(nf[i] * ng[i]);
        dft(nf);
        for(int i = 0; i < sz; i++){
            nf[i] = round(real(conj(nf[i])) / sz);
        }
        return nf;
    }
};
using FFT = Fourier_Fast_Transform;

int main(){
    i64 n;
    cin >> n;
    vector<i64> a(n),b(n);
    for(int i =0 ; i < n; i++) cin >> a[i] >> b[i];
    vector<i64> res = FFT::convolve(a,b);
    for(auto v: res)cout << res << endl;
}