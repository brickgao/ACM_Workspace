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
const int maxn = 200010;
const int INF = 1000010;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct record {
    int mx, mi;
} record;

record sum[maxn << 2];

void PushUP(int rt) {
    sum[rt].mi = min(sum[rt << 1].mi, sum[rt << 1 | 1].mi);
    sum[rt].mx = max(sum[rt << 1].mx, sum[rt << 1 | 1].mx);
}

void build(int l, int r, int rt) {
    if(l == r) {
        scanf("%d", &sum[rt].mx);
        sum[rt].mi = sum[rt].mx;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);
}

record query(int L, int R, int l, int r, int rt) {
    if(L <= l && R >= r) {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    record ret;
    ret.mi = INF;
    ret.mx = -1;
    if(L <= m) {
        record tmp = query(L, R, lson);
        ret.mi = min(ret.mi, tmp.mi);
        ret.mx = max(ret.mx, tmp.mx);
    }
    if(R > m) {
        record tmp = query(L, R, rson);
        ret.mi = min(ret.mi, tmp.mi);
        ret.mx = max(ret.mx, tmp.mx);
    }
    return ret;
}

int main() {
    int n, q;
    while(scanf("%d%d", &n, &q) != EOF) {
        build(1, n, 1);
        for(int i = 0; i < q; i ++) {
            int a, b;
            scanf("%d%d", &a, &b);
            record ret = query(a, b, 1, n, 1);
            printf("%d\n", ret.mx - ret.mi);
        }
    }
    return 0;
}

