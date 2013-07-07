//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 100010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int L, T, O;
int hash[31];
int sum[maxn << 2];
int col[maxn << 2];

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

void update(int L, int R, int c, int l, int r, int rt) {
    if((c * (r - l + 1)) == sum[rt]) return;
    if(L <= l && r <= R) {
        col[rt] = c;
        sum[rt] = c * (r - l + 1);
        return;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(L <= m) update(L, R, c, lson);
    if(R > m) update(L, R, c, rson);
    sum[rt] = 0;
}

void query(int L, int R, int l, int r, int rt) {
    if(sum[rt] > 0) {
        hash[sum[rt] / (r - l + 1)] = 1;
        return;
    }
    int m = (l + r) >> 1;
    if(L <= m) query(L, R, lson);
    if(R > m) query(L, R, rson);
    return;
}

void build(int l, int r, int rt) {
    col[rt] = 0;
    sum[rt] = 1;
    if(l == r) return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);
    return;
}

int main() {
    scanf("%d%d%d", &L, &T, &O);
    build(1, L, 1);
    while(O --) {
        char c[5];
        scanf("%s", c);
        if(c[0] == 'C') {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
            update(x, y, z, 1, L, 1);
        }
        if(c[0] == 'P') {
            int x, y;
            scanf("%d%d", &x, &y);
            memset(hash, 0, sizeof(hash));
            int ret = 0;
            query(x, y, 1, L, 1);
            for(int i = 1; i <= T; i ++) {
                if(hash[i])
                    ret ++;
            }
            printf("%d\n", ret);
        }
    }
    return 0;
}

