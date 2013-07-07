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
const int maxn = 20100;
const double PI = acos(- 1.0);
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int n, c;
double sx[maxn << 2], sy[maxn << 2], sd[maxn << 2];
int angel[maxn];

void rotate(int rt, int sd) {
    double d = sd * asin(1.0) / 90.0;
    double x = cos(d) * sx[rt] - sin(d) * sy[rt];  
    double y = sin(d) * sx[rt] + cos(d) * sy[rt];  
    sx[rt] = x,sy[rt] = y;  
}

void PushUP(int rt) {
    sx[rt] = sx[rt << 1] + sx[rt << 1 | 1];
    sy[rt] = sy[rt << 1] + sy[rt << 1 | 1];
}

void PushDown(int rt) {
    rotate(rt << 1, sd[rt]);
    rotate(rt << 1 | 1, sd[rt]);
    sd[rt << 1] += sd[rt];
    sd[rt << 1 | 1] += sd[rt];
    sd[rt] = 0;
}

void build(int l, int r, int rt) {
    sd[rt] = 0;
    if(l == r) {
        scanf("%lf", &sy[rt]);
        sx[rt] = 0;
        return;
    }
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
    PushUP(rt);
}

void update(int p, int d, int l, int r, int rt) {
    if(p < l) {
        rotate(rt, d);
        sd[rt] += d;
        return;
    }
    if(sd[rt])  PushDown(rt);
    int m = (l + r) >> 1;
    if(p < m)   update(p, d, lson);
    update(p, d, rson);
    PushUP(rt);
}

int main() {
    bool flag = false;
    while(scanf("%d%d", &n, &c) != EOF) {
        if(flag) {
            puts("");
        }
        flag = true;
        build(1, n, 1);
        //cout << n << " " << c << endl;
        for(int i = 0; i <= n; i ++) {
            angel[i] = 180;
        }
        for(int i = 0; i < c; i ++) {
            int s, a;
            scanf("%d%d", &s, &a);
            update(s, a - angel[s], 1, n, 1);
            angel[s] = a;
            if(fabs(sx[1]) < 1e-8)
                sx[1] = 0;
            if(fabs(sy[1]) < 1e-8)
                sy[1] = 0;
            printf("%.2lf %.2lf\n", sx[1], sy[1]);
        }
    }
    return 0;
}

