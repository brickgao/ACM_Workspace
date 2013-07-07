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
const int maxn = 100010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct record {
    int h, xl, xr, v;
} record;

int n, minl, maxr;
record rec[100010];
int sum[maxn << 2];
int col[maxn << 2];

bool cmp(record a, record b) {
    return a.h > b.h;
}

void PushUP(int rt) {
    sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);
}

void PushDown(int rt) {
    if(col[rt]) {
        sum[rt << 1] = col[rt << 1] = col[rt];
        sum[rt << 1 | 1] = col[rt << 1 | 1] = col[rt];
        col[rt] = 0;
    }
}

void update(int L, int R, int c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        sum[rt] = col[rt] = c;
        return;
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    if(L <= m)  update(L, R, c, lson);
    if(R > m)   update(L, R, c, rson);
    PushUP(rt);
}

void build(int l, int r, int rt) {
    col[rt] = 0;
    sum[rt] = 0;
    if(l == r)  return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R)
        return sum[rt];
    PushDown(rt);
    int m = (l + r) >> 1, ret = 0;
    if(L <= m)
        ret = max(ret, query(L, R, lson));
    if(m < R)
        ret = max(ret, query(L, R, rson));
    return ret;
}

int main() {
    while(scanf("%d", &n) != EOF) {
        minl = 100010, maxr = -1;
        for(int i = 0; i < n; i ++) {
            scanf("%d%d%d%d", &rec[i].h, &rec[i].xl, &rec[i].xr, &rec[i].v);
            minl = min(minl, rec[i].xl), maxr = max(maxr, rec[i].xr);
        }
        sort(rec, rec + n, cmp);
        build(1, maxr, 1);
        update(rec[0].xl, rec[0].xl, 100 + rec[0].v, 1, maxr, 1);
        update(rec[0].xr, rec[0].xr, 100 + rec[0].v, 1, maxr, 1);
        for(int i = 1; i < n; i ++) {
            int tmp = query(rec[i].xl, rec[i].xr, 1, maxr, 1);
            if(tmp > 0) {
                update(rec[i].xl, rec[i].xr, -1, 1, maxr, 1);
                update(rec[i].xl, rec[i].xl, tmp + rec[i].v, 1, maxr, 1);
                update(rec[i].xr, rec[i].xr, tmp + rec[i].v, 1, maxr, 1);
            }
        }
        printf("%d\n", sum[1] > 0 ? sum[1] : -1);
    }
    return 0;
}

