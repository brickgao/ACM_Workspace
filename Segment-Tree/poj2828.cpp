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

int index;
int sum[maxn << 2];
int pos[maxn], val[maxn], ans[maxn];

void build(int l, int r, int rt) {
    sum[rt] = r - l + 1;
    if(l == r)  return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

void PushUP(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int p, int l, int r, int rt) {
    if(l == r) {
        sum[rt] --;
        index = l;
        return;
    }
    int m = (l + r) >> 1;
    if(sum[rt << 1] >= p)
        update(p, lson);
    else {
        p -= sum[rt << 1];
        update(p, rson);
    }
    PushUP(rt);
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        build(1, n, 1);
        for(int i = 0; i < n; i ++) {
            scanf("%d%d", &pos[i], &val[i]);
        }
        for(int i = n - 1; i >= 0; i --) {
            update(pos[i] + 1, 1, n, 1);
            ans[index] = val[i];
            //cout << sum[1] << endl;
        }
        for(int i = 1; i <= n; i ++) {
            if(i - 1)   printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}

