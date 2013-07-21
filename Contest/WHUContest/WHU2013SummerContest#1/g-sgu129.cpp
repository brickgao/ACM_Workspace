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
const int maxint = -1u>>1;
const double eps = 1e-6;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct Point {
    double x, y;
    Point() {};
    Point(double _x, double _y) {
        x = _x, y = _y;
    }
    bool operator < (const Point &cmp) const {
        return (y < cmp.y) || (y == cmp.y && x < cmp.x);
    }
    friend Point operator - (Point s, Point e) {
        return Point(s.x - e.x, s.y - e.y);
    }
    friend double operator * (Point a, Point b) {
        return a.x * b.y - a.y * b.x;
    }
    double getlen() {
        return sqrt(x * x + y * y);
    }
} Point;

typedef struct Seg {
    Point s, t;
} Seg;

int N, M;
double res;
Seg s[10];
bool is[10];
Point po[410];

inline int sgn(double x) {
    return (x > eps) - (x < -eps);
}

inline bool is_colline(Seg a, Seg b) {
    return sgn((a.s - b.s) * (a.s - b.t)) == 0
        && sgn((a.t - b.s) * (a.t - b.t)) == 0;
}

inline bool isIntersect(Seg a, Seg b) {
    if(max(a.s.x, a.t.x) < min(b.s.x, b.t.x) - eps ||
       max(a.s.y, a.t.y) < min(b.s.y, b.t.y) - eps ||
       max(b.s.x, b.t.x) < min(a.s.x, a.t.x) - eps ||
       max(b.s.y, b.t.y) < min(a.s.y, a.t.y) - eps)
        return false;
    if(((a.t - a.s) * (b.t - a.s)) * ((a.t - a.s) * (b.s - a.s)) > eps ||
       ((b.t - b.s) * (a.t - b.s)) * ((b.t - b.s) * (a.s - b.s)) > eps)
        return false;
    return true;
}

inline Point intersection(Point as, Point ae, Point bs, Point be)
{
    Point res = as;
    double t = ((as - bs) * (bs - be)) / ((as - ae) * (bs - be));
    res.x += (ae.x - as.x) * t;
    res.y += (ae.y - as.y) * t;
    return res;
}

bool is_inpol(Point p) {
    Seg tests;
    int res = 0;
    tests.s.x = - maxint, tests.s.y = p.y;
    tests.t = p;
    for(int i = 0; i < N; ++ i) {
        Seg nows;
        nows.s = po[i];
        nows.t = po[(i + 1) % N];
        if(isIntersect(nows, tests)) {
            Point crpo;
            crpo = intersection(nows.s, nows.t, tests.s, tests.t);
            if(crpo.y == min(nows.s.y, nows.t.y))   continue;
            ++ res;
        }
    }
    if(res % 2) return true;
    else        return false;
}

void slove(int top) {
    Point mid;
    for(int i = 0; i <= top; ++ i) {
        mid.x = (s[i].s.x + s[i].t.x) / 2.0;
        mid.y = (s[i].s.y + s[i].t.y) / 2.0;
        if(!is[i] && is_inpol(mid))   res += (s[i].s - s[i].t).getlen();
    }
}

bool cmp(Point a, Point b) {
    if(sgn((a - po[0]) * (b - po[0])) == 1)
        return true;
    if(!sgn((a - po[0]) * (b - po[0])))
        return true;
    return false;
}

int main() {
    while(scanf("%d", &N) != EOF) {
        for(int i = 0; i < N; ++ i)     scanf("%lf%lf", &po[i].x, &po[i].y);
        for(int i = 1; i < N; i ++)
            if(po[0].y > po[i].y || (po[0].y == po[i].y && po[0].x > po[i].x))
            {
                Point tmp = po[0];
                po[0] = po[i];
                po[i] = tmp;
            }
        sort(po + 1, po + N, cmp);
        scanf("%d", &M);
        for(int i = 0; i < M; ++ i) {
            res = 0.0;
            int top = 0;
            scanf("%lf%lf%lf%lf", &s[0].s.x, &s[0].s.y, &s[0].t.x, &s[0].t.y);
            memset(is, false, sizeof(is));
            for(int k = 0; k <= top; ++ k) {
                for(int j = 0; j < N; ++ j) {
                    Seg nows;
                    nows.s = po[j];
                    nows.t = po[(j + 1) % N];
                    if(is_colline(nows, s[k])) {
                        is[k] = true;
                        break;
                    }
                    if(isIntersect(nows, s[k])) {
                        Point crpo;
                        crpo = intersection(nows.s, nows.t, s[k].s, s[k].t);
                        if(sgn(crpo.x - s[k].s.x) == 0 && sgn(crpo.y - s[k].s.y) == 0)  continue;
                        if(sgn(crpo.x - s[k].t.x) == 0 && sgn(crpo.y - s[k].t.y) == 0)  continue;
                        ++ top;
                        s[top] = s[k];
                        s[top].s = crpo;
                        s[k].t = crpo;
                    }
                }
            }
            slove(top);
            printf("%.6lf\n", res);
        }
    }
    return 0;
}

