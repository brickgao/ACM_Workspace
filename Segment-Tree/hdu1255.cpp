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
const int maxn = 100010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

struct Seg {
    double h, l, r;
    int s;
    Seg() {}
    Seg(double a, double b, double c, double d) : l(a), r(b), h(c), s(d) {}
    bool operator < (const Seg & cmp) const {
        return h < cmp.h;
    }
} ss[maxn];

int t;
int col[maxn << 2];
double sum[maxn << 2], sum2[maxn << 2];
double X[maxn];

void PushUP(int rt, int l, int r) {
    if(col[rt] >= 2) {
        sum2[rt] = X[r + 1] - X[l];
        sum[rt] = 0;
    }
    else if(col[rt] == 1) {
        if(l == r) {
            sum2[rt] = 0;
            sum[rt] = X[r + 1] - X[l];
        }
        else {
            sum2[rt] = sum[rt << 1 | 1] + sum[rt << 1] + sum2[rt << 1] + sum2[rt << 1 | 1];
            sum[rt] = X[r + 1] - X[l] - sum2[rt];
        }
    }
    else {
        if(l == r) {
            sum[rt] = sum2[rt] = 0;
        }
        else {
            sum[rt] = sum[rt << 1 | 1] + sum[rt << 1] ;  
            sum2[rt] = sum2[rt << 1 | 1] + sum2[rt << 1];
        }
    }
}

void update(int L, int R, int c, int l, int r, int rt) {
    if(L <= l && r <= R) {
        col[rt] += c;
        PushUP(rt, l, r);
        return;
    }
    int m = (l + r) >> 1;
    if(L <= m)  update(L, R, c, lson);
    if(m < R)   update(L, R, c, rson);
    PushUP(rt, l, r);
}

int Bin(double key, int n, double X[]) {
    int l = 0, r = n - 1;
    while(l <= r) {
        int m = (l + r) >> 1;
        if(X[m] == key) 
            return m;
        if(X[m] < key)  
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}

int main() {
    int n;
    while(scanf("%d", &t) != EOF) {
        while(t --) {
            int m = 0;
            scanf("%d", &n);
            while(n --) {
                double a, b, c, d;
                scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
                X[m] = a;
                ss[m ++] = Seg(a, c, b, 1);
                X[m] = c;
                ss[m ++] = Seg(a, c, d, -1);
            }
            sort(X, X + m);
            sort(ss, ss + m);
            int k = 1;
            for(int i = 1; i < m; i ++) {
                if(X[i] != X[i - 1])
                    X[k ++] = X[i];
            }
            memset(col, 0, sizeof(col));
            memset(sum, 0, sizeof(sum));
            memset(sum2, 0, sizeof(sum2));
            double ret = 0;
            for(int i = 0; i < m - 1; i ++) {
                int l = Bin(ss[i].l, k, X);
                int r = Bin(ss[i].r, k, X) - 1;
                if(l <= r)
                    update(l, r, ss[i].s, 0, k - 1, 1);
                ret += sum2[1] * (ss[i + 1].h - ss[i].h);
            }
            printf("%.2lf\n", ret);
        }
    }
}
