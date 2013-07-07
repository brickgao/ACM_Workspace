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
const int maxn = 20010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

struct point {
    LL x, y;
    int c;
    bool operator < (const point &cmp) const {
        return y < cmp.y;
    }
} p[maxn];

int col[maxn << 2], sum[maxn << 2];
LL ss[maxn];

void PushUP(int rt) {
    sum[rt] = max(sum[rt << 1], sum[rt << 1 | 1]);
}

void PushDown(int rt) {
    if(col[rt] != 0) {
        sum[rt << 1] += col[rt];
        sum[rt << 1 | 1] += col[rt];
        col[rt << 1] += col[rt];
        col[rt << 1 | 1] += col[rt];
        col[rt] = 0;
    }
}

void update(int L, int R, int c, int l, int r, int rt) {
    //cout << l << " " << r << " " << c << endl;
    if(L <= l && R >= r) {
        col[rt] += c;
        sum[rt] += c;
        return;
    }
    PushDown(rt);
    int m = (l + r) >> 1;
    if(L <= m)  update(L, R, c, lson);
    if(R > m)   update(L, R, c, rson);
    PushUP(rt);
}

int main() {
    int n;
    LL w, h;
    while(scanf("%d%I64d%I64d", &n, &w, &h) != EOF) {
        int ans = 0;
        int m = 0;
        memset(col, 0, sizeof(col));
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < n; i ++) {
            scanf("%I64d%I64d%d", &p[i].x, &p[i].y, &p[i].c);
            ss[m ++] = p[i].x;
            ss[m ++] = p[i].x + w;
        }
        sort(p, p + n);
        sort(ss, ss + m);
        int k = 0;
        k = unique(ss, ss + m) - ss;
        for(int i = 0, j = 0; i < n; i ++) {
            int le = lower_bound(ss, ss + k, p[i].x) - ss;
            int ri = lower_bound(ss, ss + k, p[i].x + w) - ss - 1;
            //cout << "= 3=" << endl;
            update(le, ri, p[i].c, 0, k - 1, 1);
            while(j <= i && p[i].y - p[j].y >= h) {
                le = lower_bound(ss, ss + k, p[j].x) - ss;
                ri = lower_bound(ss, ss + k, p[j].x + w) - ss - 1;
                update(le, ri, 0 - p[j].c, 0, k - 1, 1);
                j ++;
            }
            ans = max(ans, sum[1]);
        }
        printf("%d\n", ans);
    }
    return 0;
}

