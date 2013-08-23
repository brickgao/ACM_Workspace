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
const LL mod = 1000000009;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

LL n, m, k;

LL quickpow(LL a, LL b, LL m) {
    LL ans = 1;
    while(b) {
        if(b & 1) {
            ans = (ans * a) % m;
            b --;
        }
        b /= 2;
        a = a * a % m;
    }
    return ans;
}



int main() {
    cin >> n >> m >> k;
    LL res = n - m;
    LL gro = m / (k - 1);
    LL ans = 0;
    if(m % (k - 1) != 0)    ++ gro;
    -- gro;
    if(gro <= res) {
        ans = m;
    }
    else {
        int tmp = m - res * (k - 1);
        //cout << (quickpow(2, 4, mod) - 2) << endl;
        ans = (quickpow(2, tmp / k + 1, mod) - 2 + mod) * (k % mod) % mod;
        //cout << ans % mod << endl;
        ans += res * (k - 1) + tmp % k;
        ans %= mod;
    }
    cout << ans << endl;
    return 0;
}

