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
const int maxn = 8050;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct line {
    int x, y1, y2;
    bool operator < (const line &cmp) const {
        if(x == cmp.x)  return y1 < cmp.y1;
        return x < cmp.x;
    }
} line;

line recl[maxn];
int t, n;
int sum[maxn << 3];
bool vis[maxn][maxn];

void PushDown(int rt, int m) {
    if(sum[rt]) {
        sum[rt << 1] = sum[rt << 1 | 1] = sum[rt];
    }
}

void update(int L, int R, int c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        sum[rt] = c;
        return;
    }
    PushDown(rt, r - l + 1);
    int m = (l + r) >> 1;
    if(L <= m)  update(L, R, c, lson);
    if(m < R)   update(L, R, c, rson);
    sum[rt] = 0;
    return;
}

void query(int L, int R, int c, int l, int r, int rt) {
    if(L <= l && r <= R && sum[rt] > 0) {
        //cout << c << " " << sum[rt] << endl;
        vis[sum[rt]][c] = vis[c][sum[rt]] = true;
        return;
    }
    PushDown(rt, r - l + 1);
    if(l == r) {
        return;
    }
    int m = (l + r) >> 1;
    if(L <= m)  query(L, R, c, lson);
    if(m < R)   query(L, R, c, rson);
    return;
}

int main() {
    scanf("%d", &t);
    while(t --) {
        int ans = 0;
        int maxr = 0;
        scanf("%d", &n);
        memset(vis, false, sizeof(vis));
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < n; i ++) {
            int a, b;
            scanf("%d%d%d", &a, &b, &recl[i].x);
            a <<= 1;
            b <<= 1;
            recl[i].y1 = min(a, b);
            recl[i].y2 = max(a, b);
            maxr = max(maxr, recl[i].y2);
        }
        sort(recl, recl + n);
        update(recl[0].y1, recl[0].y2, 1, 0, maxr, 1);
        for(int i = 1; i < n; i ++) {
            query(recl[i].y1, recl[i].y2, i + 1, 0, maxr, 1);
            for(int j = 0; j < i; j ++) {
                if(vis[i + 1][j + 1]) {
                    for(int k = 0; k < j; k ++) {
                        if(vis[i + 1][k + 1] && vis[j + 1][k + 1]) {
                            ans ++;
                        }
                    }
                }
            }
            update(recl[i].y1, recl[i].y2, i + 1, 0, maxr, 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}

