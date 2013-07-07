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
const int maxn = 50010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int sum[maxn << 2];
int lsum[maxn << 2], rsum[maxn << 2];
int cover[maxn << 2];
int n, m;

void PushUP(int rt, int m) {
    lsum[rt] = lsum[rt << 1];
    rsum[rt] = rsum[rt << 1 | 1];
    if(lsum[rt] == m - (m >> 1)) lsum[rt] += lsum[rt << 1 | 1];
    if(rsum[rt] == (m >> 1))    rsum[rt] += rsum[rt << 1];
    sum[rt] = max(lsum[rt << 1 | 1] + rsum[rt << 1], max(sum[rt << 1], sum[rt << 1 | 1]));
}

void PushDown(int rt, int m) {
    if(cover[rt] != -1) {
        cover[rt << 1] = cover[rt << 1 | 1] = cover[rt];
        sum[rt << 1] = lsum[rt << 1] = rsum[rt << 1] = cover[rt] ? 0 : m - (m >> 1);
        sum[rt << 1 | 1] = lsum[rt << 1 | 1] = rsum[rt << 1 | 1] = cover[rt] ? 0 : (m >> 1);
        cover[rt] = -1;
    }
}

void build(int l, int r, int rt) {
    sum[rt] = lsum[rt] = rsum[rt] = r - l + 1;
    cover[rt] = -1;
    if(l == r)  {
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

void update(int L, int R, int c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        sum[rt] = lsum[rt] = rsum[rt] = c ? 0 : r - l + 1;
        cover[rt] = c;
        return;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(L <= m)  update(L, R, c, lson);
    if(m < R)   update(L, R, c, rson);
    PushUP(rt, r - l + 1);
}

int query(int w, int l, int r, int rt) {
    if(l == r)  return l;
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(sum[rt << 1] >= w)   return query(w, lson);
    else if (rsum[rt << 1] + lsum[rt << 1 | 1] >= w) return m - rsum[rt << 1] + 1;
    return query(w, rson);
}

int main() {
    scanf("%d%d", &n, &m);
    build(1, n, 1);
    while(m --) {
        int op;
        scanf("%d", &op);
        if(op == 1) {
            int x;
            scanf("%d", &x);
            if(sum[1] < x)  printf("0\n");
            else {
                int p = query(x, 1, n, 1);
                printf("%d\n", p);
                update(p, p + x - 1, 1, 1, n, 1);
            }
        }
        else {
            int x, y;
            scanf("%d%d", &x, &y);
            update(x, x + y - 1, 0, 1, n, 1);
        }
    }
}

