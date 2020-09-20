#include<iostream>
#include<vector>
#include<complex>
#include<algorithm>
#include<cmath>
using namespace std;
using i64 = int_fast64_t;
using i32 = int_fast32_t;
class Fast_Fourier_Transform{
    static void dft(vector<complex<long double>> &a,int inverse) {
        i32 n = a.size();
        if(n == 1) return;
        i32 h = 0;
        for(i32 i = 0; (1 << i) < n; i++) h++;
        for(i32 i = 0; i < n; i++){
            int j = 0;
            for(int k = 0; k < h; k++) j |= (i >> k & 1) << (h - 1 - k);
            if(i < j)swap(a[i],a[j]);
        }

        for(i32 i = 1; i < n; i *= 2){
            for(int j = 0; j < i; j++){
                complex<long double> zeta = polar(1.0,inverse * acos(-1) * j * 2 / (2 * i));
                for(i32 k = 0; k < n; k += 2 * i){
                    complex<long double> s = a[j + k],t = a[j + k + i] * zeta;
                    a[j + k] += t;
                    a[j + k + i] = s - t;
                }
            }
        }
    }
public:
    template<typename T>
    static vector<T> convolve(vector<T> f, vector<T> g){

        i64 sz = 1;
        while(sz < f.size() + g.size()) sz *= 2;
        vector<complex<long double>> nf(sz),ng(sz);
        for(i32 i = 0; i < f.size(); i++){
            nf[i] = f[i];
            ng[i] = g[i];
        }
        dft(nf,1);
        dft(ng,1);
        vector<T> res(sz);
        for(i32 i = 0; i < sz ; i++) nf[i] = nf[i] * ng[i];
        dft(nf,-1);
        for(i32 i = 0; i < sz; i++){
            res[i] = round(nf[i].real() / sz);
        }
        return res;
    }
};
using FFT = Fast_Fourier_Transform;