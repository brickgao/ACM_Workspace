//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxn = 100010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int t, caseno = 1;
int n, q;
int col[maxn << 2];
int sum[maxn << 2];

void PushUp(int rt) {
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

void update(int L, int R, int c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        col[rt] = c;
        sum[rt] = c * (r - l + 1);
        return;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(L <= m)  update(L, R, c, lson);
    if(R > m)   update(L, R, c, rson);
    PushUp(rt);
}

void build(int l, int r, int rt) {
    col[rt] = 0;
    sum[rt] = 1;
    if(l == r)  return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUp(rt);
}

int main() {
    scanf("%d", &t);
    while(t --) {
        scanf("%d%d", &n, &q);
        build(1, n, 1);
        while(q --) {
            int x, y ,z;
            scanf("%d%d%d", &x, &y, &z);
            update(x, y, z, 1, n, 1);
        }
        printf("Case %d: The total value of the hook is %d.\n", caseno ++, sum[1]);
    }
    return 0;
}

