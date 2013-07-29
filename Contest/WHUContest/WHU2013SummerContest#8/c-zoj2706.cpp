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
const int maxn = 30010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int n, m;
LL sum[maxn << 2], col[maxn << 2];

void PushUP(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void PushDown(int rt, int m) {
    if(col[rt]) {
        col[rt << 1] = col[rt << 1 | 1] = col[rt];
        sum[rt << 1] = (m - (m >> 1)) * col[rt];
        sum[rt << 1 | 1] = (m >> 1) * col[rt];
        col[rt] = 0;
    }
}

void update(int L, int R, LL c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        sum[rt] = c * (r - l + 1);
        col[rt] = c;
        return;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(L <= m)  update(L, R, c, lson);
    if(R > m)   update(L, R, c, rson);
    sum[rt] = 0;
    PushUP(rt);
}

void build(int l, int r, int rt) {
    col[rt] = 0;
    if(l == r) {
        scanf("%lld", &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);
}

LL query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return sum[rt];
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    LL ret = 0;
    if(L <= m)  ret += query(L, R, lson);
    if(R > m)   ret += query(L, R, rson);
    return ret;
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        build(1, n, 1);
        LL osum = query(1, n, 1, n, 1);
        for(int i = 0; i < m; ++ i) {
//            for(int i = 1; i <= n; ++ i) {
//                if(i != 1)  printf(" ");
//                printf("%d", query(i, i, 1, n, 1));
//            }
//            puts("");
            int t1, t2;
            scanf("%d%d", &t1, &t2);
            if(t1 > t2) swap(t1, t2);
            LL tsum = query(t1, t2, 1, n, 1);
            LL avg = tsum / (t2 - t1 + 1);
            //cout << tsum << " " << avg << endl;
            if(tsum % (t2 - t1 + 1) == 0) {
                update(t1, t2, avg, 1, n, 1);
            }
            else {
                LL nsum = query(1, n, 1, n, 1);
                if(avg < 0)
                    -- avg;
                if(nsum <= osum) {
                    ++ avg;
                }
                update(t1, t2, avg, 1, n, 1);
            }
        }
        for(int i = 1; i <= n; ++ i) {
            if(i != 1)  printf(" ");
            printf("%lld", query(i, i, 1, n, 1));
        }
        puts("");
        puts("");
    }
    return 0;
}

