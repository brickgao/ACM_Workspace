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
const int maxn = 1010;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int m;
int sum[maxn << 2][maxn << 2];

void PushUP(int rt, int t) {
    sum[t][rt] = max(sum[t][rt << 1], sum[t][rt << 1 | 1]);
}

void subbuild(int l, int r, int rt, int t) {
    sum[t][rt] = -1;
    if(l == r)
        return;
    int m = (l + r) >> 1;
    subbuild(lson, t);
    subbuild(rson, t);
}

void build(int l, int r, int rt) {
    subbuild(0, 1000, 1, rt);
    if(l == r)
        return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

void subupdate(int l, int r, int rt, int y, int c, int t) {
    if(l == r) {
        sum[t][rt] = max(sum[t][rt], c);
        return;
    }
    int m = (l + r) >> 1;
    if(y <= m)  subupdate(lson, y, c, t);
    else        subupdate(rson, y, c, t);
    PushUP(rt, t);
}
    
void update(int l, int r, int rt, int x, int y, int c) {
    subupdate(0, 1000, 1, y, c, rt);
    if(l == r)
        return;
    int m = (l + r) >> 1;
    if(x <= m)      update(lson, x, y, c);
    else            update(rson, x, y, c);
}

int subquery(int l, int r, int rt, int LY, int RY, int t) {
    if(LY <= l && RY >= r) {
        return sum[t][rt];
    }
    int m = (l + r) >> 1;
    int ret = -1;
    if(LY <= m)     ret = max(ret, subquery(lson, LY, RY, t));
    if(RY > m)      ret = max(ret, subquery(rson, LY, RY, t));
    return ret;
}

int query(int l, int r, int rt, int LX, int RX, int LY, int RY) {
    if(LX <= l && RX >= r) {
        return subquery(0, 1000, 1, LY, RY, rt);
    }
    int m = (l + r) >> 1;
    int ret = -1;
    if(LX <= m)     ret = max(ret, query(lson, LX, RX, LY, RY));
    if(RX > m)      ret = max(ret, query(rson, LX, RX, LY, RY));
    return ret;
}

int main() {
    while(scanf("%d", &m) != EOF) {
        if(m == 0)  return 0;
        build(100, 200, 1);
        while(m --) {
            char op[4];
            scanf("%s", op);
            if(op[0] == 'I') {
                int h;
                double a, l;
                scanf("%d%lf%lf", &h, &a, &l);
                update(100, 200, 1, h, int(a * 10), int(l * 10));
            }
            else {
                double h1, h2, a1, a2;
                scanf("%lf%lf%lf%lf", &h1, &h2, &a1, &a2);
                if(h1 > h2)     swap(h1, h2);
                if(a1 > a2)     swap(a1, a2);
                double ret = double(query(100, 200, 1, (int)h1, (int)h2, int(a1 * 10), int(a2 * 10))) / 10;
                if(ret < 0)
                    printf("-1\n");
                else
                    printf("%.1lf\n", ret);
            }
        }
    }
    return 0;
}

