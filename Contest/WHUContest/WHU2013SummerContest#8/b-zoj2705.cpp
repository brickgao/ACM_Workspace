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

LL m, n;
LL rec[100];

int main() {
    rec[0] = 1, rec[1] = 1;
    for(int i = 2; i < 70; ++ i) {
        rec[i] = rec[i - 1] + rec[i - 2];
    }
    while(scanf("%lld%lld", &m, &n) != EOF) {
        LL ans = 0;
        LL res = 0;
        bool flag1 = false, flag2 = false;
        for(int i = 1; i < 70; ++ i) {
            if(m % (rec[i] + rec[i - 1]) == 0) {
                res = n * (m - m / (rec[i] + rec[i - 1]));
                flag1 = true;
                ans = max(ans, res);
            }
        }
        for(int i = 1; i < 70; ++ i) {
            if(n % (rec[i] + rec[i - 1]) == 0) {
                res = m * (n - n / (rec[i] + rec[i - 1]));
                flag2 = true;
                ans = max(ans, res);
            }
        }
        if(!flag1 && !flag2) {
            puts("0");
        }
        else {
            printf("%lld\n", ans);
        }
        puts("");
    }
    return 0;
}

