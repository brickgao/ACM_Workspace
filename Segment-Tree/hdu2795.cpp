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
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define LL long long 
const int maxn =  200010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

LL h, w, n;
LL sum[maxn << 2];

void PushUP(int rt) {
    sum[rt] = max(sum[rt << 1] ,sum[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
    sum[rt] = w;
    if(l == r) return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

LL query(LL c, int l, int r, int rt) {
    if(l == r) {
        sum[rt] -= c;
        return l;
    }
    int m = (l + r) >> 1;
    LL ret;
    if(sum[rt << 1] >= c) {
        ret = query(c, lson);
    }
    else {
        ret = query(c, rson);
    }
    PushUP(rt);
    return ret;
}

int main() {
    while(scanf("%I64d%I64d%I64d", &h, &w, &n) != EOF) {
        if(h > n) h = n;
        build(1, h, 1);
        while(n --) {
            LL x;
            scanf("%I64d", &x);
            if(sum[1] < x) {
                printf("-1\n");
            }
            else {
                printf("%I64d\n", query(x, 1, h, 1));
            }
        }
    }
    return 0;
}

