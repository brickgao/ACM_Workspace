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

int k;
LL f[52];
LL sum[52];

int main() {
    f[1] = f[2] = 1;
    for(int i = 3; i < 50; ++ i) {
        f[i] = f[i - 1] + f[i - 2];
    }
    memset(sum, 0, sizeof(sum));
    for(int i = 1; i < 50; ++ i) {
        sum[i] = sum[i - 1] + f[i];
    }
    while(scanf("%d", &k) != EOF) {
        printf("%I64d\n", sum[k]);
    }
    return 0;
}

