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
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct point {
    LL x, y;
} Point;

typedef struct line {
    point a, b;
} Line;

Line line[10010];
Point p;
int k;

inline void Swap(LL &a, LL &b) {
    LL tmp;
    tmp = a;
    a = b;
    b = tmp;
    return;
}

bool Inline(Line l, Point po) {
    if(l.a.x == l.b.x) {
        if(po.x == l.a.x && po.y >= l.a.y && po.y <= l.b.y)
            return true;
        else
            return false;
    }
    else {
        if(l.a.y == po.y && po.x >= l.a.x && po.x <= l.b.x)
            return true;
        else
            return false;
    }
}

bool Connect(Line l1, Point p) {
    if(l1.a.x == l1.b.x && l1.a.x < p.x && l1.a.y <= p.y && p.y < l1.b.y)
        return true;
    else
        return false;
}

int main() {
    while(scanf("%d", &k) != EOF) {
        for(int i = 0; i < k; ++ i) {
            scanf("%I64d%I64d%I64d%I64d", &line[i].a.x, &line[i].a.y, &line[i].b.x, &line[i].b.y);
            if(line[i].a.x == line[i].b.x) {
                if(line[i].a.y > line[i].b.y) {
                    Swap(line[i].a.y, line[i].b.y);
                }
            }
            else {
                if(line[i].a.x > line[i].b.x) {
                    Swap(line[i].a.x, line[i].b.x);
                }
            }
            //cout << line[i].a.x << " " << line[i].a.y << " " << line[i].b.x << " " << line[i].b.y << endl;
        }
        scanf("%I64d%I64d", &p.x, &p.y);
        bool flag = true;
        //cout << p.x << " " << p.y << endl;
        for(int i = 0; i < k; ++ i) {
            if(Inline(line[i], p)) {
                flag = false;
            }
        }
        if(!flag) {
            puts("BORDER");
            continue;
        }
        LL res = 0;
        for(int i = 0; i < k; ++ i) {
            if(Connect(line[i], p))
                res ++;
        }
        //cout << res << endl;
        if(res % 2 == 0) {
            puts("OUTSIDE");
        }
        else {
            puts("INSIDE");
        }
    }
    return 0;
}

