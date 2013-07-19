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

LL mod;
LL p, m;
LL rec[1000010];

LL quickpow(LL x, LL y, LL k)
{
    LL b = 1;
    while (y > 0) {
          if (y & 1)
             b = (b * x) % k;
          y = y >> 1;
          x = (x * x) % k;
    }
    return b % k;
} 


int main() {
    bool flag = false;
    while(cin >> p >> m) {
        if(flag)    puts("");
        flag = true;
        mod = 1;
        for(int i = 2; i <= m; ++ i) {
            mod *= i;
        }
        if(p % mod == 0) {
            puts("0");
            continue;
        }
        int ans = 1000009;
        rec[0] = p;
        for(int i = 1; i < 1000010; ++i) {
            rec[i] = quickpow(p, rec[i - 1], mod);
            if(rec[i] == rec[i - 1]) {
                ans = i;
                break;
            }
        }
        cout << rec[ans] << endl;
    }
    return 0;
}

