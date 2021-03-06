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
const int maxn = 200010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int t, caseno = 1;
int sum[maxn << 2];

void PushUP(int rt) {
    sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);
}

void build(int l, int r, int rt) {
    if(l == r) {
        scanf("%d", &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);
}

void update(int p, int cha, int l, int r, int rt) {
    if(l == r) {
        sum[rt] = cha;
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m)  update(p, cha, lson);
    else    update(p, cha, rson);
    PushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if(L <= m)  ret = max(ret, query(L, R, lson));
    if(R > m)   ret = max(ret, query(L, R, rson));
    return ret;
}

int main() {
    int n, m, a, b;
    while(scanf("%d%d", &n, &m) != EOF) {
        build(1, n, 1);
        char op[10];
        while(m --) {
            scanf("%s", op);
            scanf("%d%d", &a, &b);
            if(op[0] == 'Q')
                printf("%d\n", query(a, b, 1, n, 1));
            if(op[0] == 'U')
                update(a, b, 1, n, 1);
        }
    }
    return 0;
}

