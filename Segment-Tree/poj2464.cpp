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

typedef struct point {
    int x, y;
    bool operator < (const point &cmp) const {
        return x > cmp.x;
    }
}point;

point po[maxn];
int ss[maxn];
int sum1[maxn], sum2[maxn];

void PushUP(int *sum, int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int *sum, int p, int c, int l, int r, int rt) {
    if(l == r && l == p) {
        sum[rt] += c;
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m)  update(sum, p, c, lson);
    else        update(sum, p, c, rson);
    PushUP(sum, rt);
}

int query(int *sum, int L, int R, int l, int r, int rt) {
    int ret = 0;
    if(L <= l && R >= r) {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    if(L <= m)      ret += query(sum, L, R, lson);
    if(m < R)      ret += query(sum, L, R, rson);
    return ret;
}

int main() {
    int n;
    while(scanf("%d", &n) != EOF) {
        int l = 0;
        if(n == 0)  return 0;
        int k = 0;
        memset(sum1, 0, sizeof(sum1));
        memset(sum2, 0, sizeof(sum2));
        for(int i = 0; i < n; i ++) {
            scanf("%d%d", &po[i].x, &po[i].y);
            ss[i] = po[i].y;
            l = max(l, po[i].x);
        }
        sort(po, po + n);
        sort(ss, ss + n);
        k = unique(ss, ss + n) - ss;
        for(int i = 0; i < n; i ++) {
            int p = lower_bound(ss, ss + k, po[i].y) - ss;
            update(sum1, p, 1, 0, k - 1, 1);
        }
        vector <int> bef;
        vector <int> ans2;
        ans2.clear();
        int ans1 = -1;
        for(int i = 0; i < n; i ++) {
            int p = lower_bound(ss, ss + k, po[i].y) - ss;
            if(po[i].x != l) {
                int len = SZ(bef);
                int ret1 = -1, ret2 = -1;
                for(int j = 0; j < len; j ++) {
                    int tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0;
                    if(bef[j] != 0) {
                        tmp1 = query(sum1, 0, bef[j] - 1, 0, k - 1, 1);
                        tmp2 = query(sum2, 0, bef[j] - 1, 0, k - 1, 1);
                    }
                    if(bef[j] != k - 1) {
                        tmp3 = query(sum1, bef[j] + 1, k - 1, 0, k - 1, 1);
                        tmp4 = query(sum2, bef[j] + 1, k - 1, 0, k - 1, 1); 
                    }
                    int ssum = tmp1 + tmp4;
                    int osum = tmp2 + tmp3;
                    if(ret2 == osum)    ret1 = min(ret1, ssum);
                    else if(ret2 < osum)    ret1 = ssum, ret2 = osum;
                }
                if(ret1 > ans1) {
                    ans2.clear();
                    ans1 = ret1;
                }
                if(ret1 == ans1) {
                    ans2.push_back(ret2);
                }
                for(int j = 0; j < len; j ++) {
                    update(sum2, bef[j], 1, 0, k - 1, 1);
                }
                l = po[i].x;
                bef.clear();
            }
            bef.push_back(p);
            update(sum1, p, -1, 0, k - 1, 1);
        }
        int len = SZ(bef);
        int ret1 = -1, ret2 = -1;
        for(int j = 0; j < len; j ++) {
            int tmp1 = 0, tmp2 = 0, tmp3 = 0, tmp4 = 0;
            if(bef[j] != 0) {
                tmp1 = query(sum1, 0, bef[j] - 1, 0, k - 1, 1);
                tmp2 = query(sum2, 0, bef[j] - 1, 0, k - 1, 1);
            }
            if(bef[j] != k - 1) {
                tmp3 = query(sum1, bef[j] + 1, k - 1, 0, k - 1, 1);
                tmp4 = query(sum2, bef[j] + 1, k - 1, 0, k - 1, 1); 
            }
            int ssum = tmp1 + tmp4;
            int osum = tmp2 + tmp3;
            if(ret2 == osum)    ret1 = min(ret1, ssum);
            else if(ret2 < osum)    ret1 = ssum, ret2 = osum;
        }
        if(ret1 > ans1) {
            ans2.clear();
            ans1 = ret1;
        }
        if(ret1 == ans1) {
            ans2.push_back(ret2);
        }
        sort(ans2.begin(), ans2.end());
        k = unique(ans2.begin(), ans2.end()) - ans2.begin();
        printf("Stan: %d; ", ans1);
        printf("Ollie:");
        for(int i = 0; i < k; i ++) {
            printf(" %d", ans2[i]);
        }
        printf(";\n");
    }
    return 0;
}

