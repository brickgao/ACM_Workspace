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
const int maxn = 10010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int t, n;
int li[maxn], ri[maxn];
int rec[maxn << 3];
int sum[maxn << 4];
int col[maxn << 4];
int hash[maxn];

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
}

void build(int l, int r, int rt) {
    col[rt] = 0;
    if(l == r) {
        sum[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);
}

void query(int l, int r, int rt) {
    if(sum[rt] > 0) {
        LL pos = sum[rt] / (LL)(r - l + 1);
        hash[pos] = 1;
        return;
    }
    if(l == r)  return;
    int m = (l + r) >> 1;
    query(lson);
    query(rson);
    return;
}

int scan(int key, int n, int x[]) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(x[m] == key) return m;
        if(x[m] < key)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    scanf("%d", &t);
    while(t --) {
        memset(hash, 0, sizeof(hash));
        scanf("%d", &n);
        int tt = 0;
        for(int i = 0; i < n; i ++) {
            scanf("%d%d", &li[i], &ri[i]);
            rec[tt ++] = li[i];
            rec[tt ++] = ri[i];
        }
        sort(rec, rec + 2 * n);
        int m = 1;
        for(int i = 1; i < tt; i ++) {
            if(rec[i] != rec[i - 1])
                rec[m ++] = rec[i];
        }
        tt = m;
        for(int i = 1; i < tt; i ++) {
            if(rec[i] - rec[i - 1] > 1) {
                rec[m ++] = rec[i] + 1;
            }
        }
        sort(rec, rec + m);
        build(0, m, 1);
        for(int i = 0; i < n; i ++) {
            int l = scan(li[i], m, rec);
            int r = scan(ri[i], m, rec);
            update(l, r, i + 1, 0, m, 1);
        }
        query(0, m, 1);
        int res = 0;
        for(int i = 1; i <= n; i ++) {
            if(hash[i] == 1) {
                res ++;
            }
        }
        printf("%d\n", res);
    }
}

