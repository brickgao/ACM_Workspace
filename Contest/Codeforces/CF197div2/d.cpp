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
const int MAXN = (1 << 17) + 10;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int n, m;
int sum[MAXN << 2];

void PushUP(int rt, int op) {
    if(op & 1) 
        sum[rt] = sum[rt << 1] | sum[rt << 1 | 1];
    else
        sum[rt] = sum[rt << 1] ^ sum[rt << 1 | 1];
}

void build(int t, int l, int r, int rt) {
    if(l == r) {
        scanf("%d", &sum[rt]);
        return;
    }
    int m = (l + r) >> 1;
    build(t ^ 1, lson);
    build(t ^ 1, rson);
    PushUP(rt, t);
}

void update(int t, int p, int num, int l, int r, int rt) {
    if(l == r) {
        sum[rt] = num;
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m)  update(t ^ 1, p, num, lson);
    else    update(t ^ 1, p, num, rson);
    PushUP(rt, t);
}

int main() {
    scanf("%d%d", &n, &m);
    int len = 1 << n;
    build(n & 1, 1, len, 1);
    for(int i = 0; i < m; ++ i) {
        int p, d;
        scanf("%d%d", &p, &d);
        update(n & 1, p, d, 1, len, 1);
        printf("%d\n", sum[1]);
    }
    return 0;
}

