//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int quickpow(int m, int n, int mod) {
    int b = 1;
    while(n > 0) {
        if(n & 1)
            b = (b * m) % mod;
        n >>= 1;
        m = (m * m) % mod;
    }
    return b;
}

int phi(int n) {
    int m = 1;
    for(int i = 2; n > 1; ++ i) {
        if(n % i == 0) {
            m *= i - 1;
            n /= i;
            while(n % i == 0) {
                m *= i;
                n /= i;
            }
        }
    }
    return m;
}

int getval(int mod) {
    if(mod == 1)    return 0;
    int phi_num = phi(mod);
    int res = quickpow(2, phi_num + getval(phi_num), mod);
    return res;
}

int getval2(int n, int mod) {
    if(n == 1)  return 2;
    if(n == 2)  return 4;
    if(n == 3)  return 16;
    if(n == 4)  return 65536;
    int phi_num = phi(mod);
    return quickpow(2, phi_num + getval2(n - 1, phi_num), mod);
}

int main() {
    int T;
    bool blank = false;
    scanf("%d", &T);
    while(T --) {
        int m, n;
        if(blank)   puts("");
        else        blank = true;
        int mod, caseno = 0;
        scanf("%d", &mod);
        int con = getval(mod);
        //cout << con << endl;
        while(1) {
            ++ caseno;
            scanf("%d%d", &n, &m);
            if(m == 0 && n == 0)    break;
            if(mod == 1) {
                printf("Case %d: 0\n", caseno);
                continue;
            }
            int ans;
            if(n == 1)
                ans = 2 * m % mod;
            else if(n == 2)
                ans = quickpow(2, m, mod);
            else if(n == 3) {
                if(m < 32)
                    ans = getval2(m, mod) % mod;
                else
                    ans = con;
                }
            else {
                if(m == 1)
                    ans = 2 % mod;
                else if(m == 2)
                    ans = 4 % mod;
                else if(n == 4 && m == 3)
                    ans = 65536 % mod;
                else
                    ans = con;
            }
            printf("Case %d: %d\n", caseno, ans);
        }
    }
    return 0;
}

