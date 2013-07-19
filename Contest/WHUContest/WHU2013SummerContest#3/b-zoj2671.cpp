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
const int MAXN = 30010;
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int mod;

typedef struct matrix {
    int v[2][2];
    matrix operator * (const matrix &cmp) const {
        matrix ret;
        ret.v[0][0] = (v[0][0] * cmp.v[0][0] % mod + v[0][1] * cmp.v[1][0] % mod) % mod;
        ret.v[0][1] = (v[0][0] * cmp.v[0][1] % mod + v[0][1] * cmp.v[1][1] % mod) % mod;
        ret.v[1][0] = (v[1][0] * cmp.v[0][0] % mod + v[1][1] * cmp.v[1][0] % mod) % mod;
        ret.v[1][1] = (v[1][0] * cmp.v[0][1] % mod + v[1][1] * cmp.v[1][1] % mod) % mod;
        return ret;
    }
} ret;

matrix sum[MAXN << 2];
int m, n;

void PushUP(int rt) {
    sum[rt] = sum[rt << 1] * sum[rt << 1 | 1];
}

void build(int l, int r, int rt) {
    if(l == r) {
        scanf("%d%d%d%d", &sum[rt].v[0][0], &sum[rt].v[0][1], &sum[rt].v[1][0], &sum[rt].v[1][1]);
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);
}

matrix query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    matrix ret;
    ret.v[0][0] = ret.v[1][1] = 1;
    ret.v[1][0] = ret.v[0][1] = 0;
    if(L <= m)  ret = ret * query(L, R, lson);
    if(R > m)   ret = ret * query(L, R, rson);
    return ret;
}

int main() {
    bool flag = false;
    while(scanf("%d%d%d", &mod, &n, &m) != EOF) {
        if(flag)    puts("");
        flag = true;
        build(1, n, 1);
        for(int i = 0; i < m; ++ i) {
            if(i)   puts("");
            int le, ri;
            scanf("%d%d", &le, &ri);
            matrix res = query(le, ri, 1, n, 1);
            printf("%d %d\n%d %d\n", res.v[0][0], res.v[0][1], res.v[1][0], res.v[1][1]);
        }
    }
    return 0;
}

