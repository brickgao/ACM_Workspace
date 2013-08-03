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
const int maxint = -1u>>1;
const int MAXN = 50010;

int t, n, m;
int sum[MAXN << 2], lp[MAXN << 2], rp[MAXN << 2];
int col[MAXN << 2];

inline int get_min(const int a, const int b) {
    if(a > b)   return b;
    else        return a;
}

inline int get_max(const int a, const int b) {
    if(a > b)   return a;
    else        return b;
}

void PushUP(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    lp[rt] = get_min(lp[rt << 1], lp[rt << 1 | 1]);
    rp[rt] = get_max(rp[rt << 1], rp[rt << 1 | 1]);
}

void PushDown(int rt, int l, int r) {
    if(col[rt] != -1) {
        int m = r - l + 1;
        int mid = (l + r) >> 1;
        col[rt << 1] = col[rt << 1 | 1] = col[rt];
        sum[rt << 1] = (m - (m >> 1)) * col[rt];
        sum[rt << 1 | 1] = (m >> 1) * col[rt];
        if(col[rt] == 0) {
            lp[rt << 1] = l, lp[rt << 1 | 1] = mid + 1;
            rp[rt << 1] = mid, rp[rt << 1 | 1] = r;
        }
        else {
            lp[rt << 1] = lp[rt << 1 | 1] = maxint;
            rp[rt << 1] = rp[rt << 1 | 1] = - 1;
        }
        col[rt] = -1;
    }
}

void update(int L, int R, int c, int l, int r, int rt) {
    if(L <= l && R >= r) {
        col[rt] = c;
        sum[rt] = c * (r - l + 1);
        if(c == 0)  lp[rt] = l, rp[rt] = r;
        else        lp[rt] = maxint, rp[rt] = -1;
        return;
    }
    PushDown(rt, l, r);
    int m = (l + r) >> 1;
    if(L <= m)  update(L, R, c, lson);
    if(R > m)   update(L, R, c, rson);
    PushUP(rt);
}

int query_sum(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    PushDown(rt, l, r);
    if(L <= m)  ret += query_sum(L, R, lson);
    if(R > m)   ret += query_sum(L, R, rson);
    return ret;
}

int query_l(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return lp[rt];
    }
    int m = (l + r) >> 1;
    int ret = maxint;
    PushDown(rt, l, r);
    if(L <= m)  ret = get_min(ret, query_l(L, R, lson));
    if(R > m)   ret = get_min(ret, query_l(L, R, rson));
    return ret;
}

int query_r(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return rp[rt];
    }
    int m = (l + r) >> 1;
    int ret = -1;
    PushDown(rt, l, r);
    if(L <= m)  ret = get_max(ret, query_r(L, R, lson));
    if(R > m)   ret = get_max(ret, query_r(L, R, rson));
    return ret;
}

void build(int l, int r, int rt) {
    col[rt] = -1;
    sum[rt] = 0;
    lp[rt] = l, rp[rt] = r;
    if(l == r)  return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);
}

int main() {
    int t;
    while(scanf("%d", &t) != EOF) {
        while(t --) {
            scanf("%d%d", &n, &m);
            build(0, n - 1, 1);
            for(int i = 0; i < m; ++ i) {
                int op;
                scanf("%d", &op);
                if(op == 1) {
                    int a, f;
                    scanf("%d%d", &a, &f);
                    int tmp = (n - 1) - a + 1 - query_sum(a, n - 1, 0, n - 1, 1);
                    if(tmp == 0) {
                        puts("Can not put any one.");
                        continue;
                    }
                    if(tmp <= f) {
                        int resl = query_l(a, n - 1, 0, n - 1, 1);
                        int resr = query_r(a, n - 1, 0, n - 1, 1);
                        printf("%d %d\n", resl, resr);
                        update(a, n - 1, 1, 0, n - 1, 1);
                        continue;
                    }
                    int l = a, r = n - 1;
                    while(l < r) {
                        int mid = (l + r) >> 1;
                        int tmp2 = mid - a + 1 - query_sum(a, mid, 0, n - 1, 1);
                        if(tmp2 == f)   break;
                        if(tmp2 > f)    r = mid;
                        else            l = mid;
                    }
                    int mid = (l + r) >> 1;
                    int resl = query_l(a, mid, 0, n - 1, 1);
                    int resr = query_r(a, mid, 0, n - 1, 1);
                    printf("%d %d\n", resl, resr);
                    update(a, mid, 1, 0, n - 1, 1);
                }
                else {
                    int a, b;
                    scanf("%d%d", &a, &b);
                    int res = query_sum(a, b, 0, n - 1, 1);
                    printf("%d\n", res);
                    update(a, b, 0, 0, n - 1, 1);
                }
            }
            puts("");
        }
    }
    return 0;
}

