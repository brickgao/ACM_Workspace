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
const int maxn = 5010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int sum[maxn << 2];
int a[maxn];

void PushUP(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt) {
    sum[rt] = 0;
    if(l == r) return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

void update(int p, int l, int r, int rt) {
    if(l == r) {
        sum[rt] ++;
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m) update(p, lson);
    else update(p, rson);
    PushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if(L <= m) ret += query(L, R, lson);
    if(R > m) ret += query(L, R, rson);
    return ret;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int ans = 0;
        build(0, n - 1, 1);
        for(int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
            ans += query(a[i], n - 1, 0, n - 1, 1);
            update(a[i], 0, n - 1, 1);
        }
        int ret = ans;
        for(int i = 0; i < n; i ++) {
            ans += (n - a[i] - 1) - a[i];
            ret = min(ret, ans);
        }
        printf("%d\n", ret);
    }
    return 0;
}

