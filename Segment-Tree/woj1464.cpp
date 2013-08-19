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
const int maxint = -1u>>1;
const int MAXN = 100010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int t;
int n, m;
LL sum[MAXN << 2];
LL col[MAXN << 2];
bool tag[MAXN << 2];

inline void PushUP(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
    tag[rt] = tag[rt << 1] && tag[rt << 1 | 1];
}

inline void PushDown(int rt, int m) {
    if(col[rt] != 0) {
        col[rt << 1] += col[rt];
        col[rt << 1 | 1] += col[rt];
        sum[rt << 1] += (m - (m >> 1)) * col[rt];
        sum[rt << 1 | 1] += (m >> 1) * col[rt];
        col[rt] = 0;
    }
}

void build(int l, int r, int rt) {
    col[rt] = 0;
    if(l == r) {
        scanf("%lld", &sum[rt]);
        if(sum[rt] > 0) tag[rt] = false;
        else            tag[rt] = true;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);
}

void update1(int L, int R, LL c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        sum[rt] += c * (r - l + 1);
        col[rt] += c;
        return;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(L <= m)  update1(L, R, c, lson);
    if(R > m)   update1(L, R, c, rson);
    PushUP(rt);
}

void update2(int L, int R, LL c, int l, int r, int rt) {
    if(tag[rt])     return;
    if(l == r) {
        if(sum[rt] > 0)     sum[rt] /= c;
        if(sum[rt] <= 0)    tag[rt] = true;
        return;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(L <= m)  update2(L, R, c, lson);
    if(R > m)   update2(L, R, c, rson);
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
    while(scanf("%d", &t) != EOF) {
        int caseno = 1;
        while(t --) {
            scanf("%d%d", &n, &m);
            build(1, n, 1);
            printf("Case %d:\n", caseno ++);
            for(int i = 0; i < m; ++ i) {
                char op[15];
                scanf("%s", op);
                //puts(op);
//                for(int j = 1; j <= n; ++ j) {
//                    if(j)   printf(" ");
//                    cout << query(j, j, 1, n, 1);
//                }
//                cout << endl;
                if(op[0] == 'D') {
                    int a, b;
                    LL c;
                    scanf("%d%d%lld", &a, &b, &c);
                    if(c == 1)  continue;
                    update2(a, b, c, 1, n, 1);
                }
                if(op[0] == 'M') {
                    int a, b;
                    LL c;
                    scanf("%d%d%lld", &a, &b, &c);
                    update1(a, b, 0 - c, 1, n, 1);
                }
                if(op[0] == 'S') {
                    int a, b;
                    scanf("%d%d", &a, &b);
                    LL ret = query(a, b, 1, n, 1);
                    printf("%lld\n", ret);
                }
            }
            puts("");
        }
    }
    return 0;
}

