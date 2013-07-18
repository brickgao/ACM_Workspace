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
const int ADDNUM = 10000;
const int MAXN = 20010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct Point {
    int x, y, num;
} Point;

typedef struct Seg {
    int a, b, c;
} Seg;

int n, m;
Point po[10010];
Seg s[20010];
bool vis[10010];
int sum[MAXN << 2];
vector <int> p[10010];

bool cmpx(Point p1, Point p2) {
    if(p1.x != p2.x)    
        return p1.x < p2.x;
    else
        return p1.y < p2.y;
}

bool cmpy(Point p1, Point p2) {
    if(p1.y != p2.y)
        return p1.y < p2.y;
    else
        return p1.x < p2.x;
}

bool cmps(Seg s1, Seg s2) {
    if(s1.a != s2.a)
        return s1.a < s2.a;
    else
        return s1.c < s2.c;
}

void dfs(int u) {
    vis[u] = true;
    for(int i = 0; i < SZ(p[u]); ++ i) {
        int v = p[u][i];
        if(!vis[v]) {
            dfs(v);
        }
    }
}

void PushUP(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void update(int p, int add, int l, int r, int rt) {
    if(l == r) {
        sum[rt] += add;
        return;
    }
    int m = (l + r) >> 1;
    if(p <= m)  update(p, add, lson);
    else        update(p, add, rson);
    PushUP(rt);
}

int query(int L, int R, int l, int r, int rt) {
    if(L <= l && r <= R) {
        return sum[rt];
    }
    int m = (l + r) >> 1;
    int ret = 0;
    if(L <= m)  ret += query(L, R, lson);
    if(R > m)   ret += query(L, R, rson);
    return ret;
}

int main() {
    while(scanf("%d", &n) != EOF) {
        bool flag = true;
        int ans = 0;
        m = 0;
        for(int i = 0; i < n; ++ i) p[i].clear();
        for(int i = 0; i < n; ++ i) {
            scanf("%d%d", &po[i].x, &po[i].y);
            po[i].x += ADDNUM, po[i].y += ADDNUM;
            po[i].num = i;
        }
        sort(po, po + n, cmpx);
        for(int lower = 0; lower < n; ++ lower) {
            int upper = lower + 1;
            while(upper < n && po[lower].x == po[upper].x) {
                upper ++;
            }
            if((upper - lower) % 2)  flag = false;
            for(int i = lower; i < upper; i += 2) {
                if(i + 1 < upper) {
                    p[po[i].num].push_back(po[i + 1].num);
                    p[po[i + 1].num].push_back(po[i].num);
                    s[m].a = po[i].x; s[m].b = po[i].y; s[m ++].c = po[i + 1].y;
                    ans += po[i + 1].y - po[i].y;
                }
            }
            lower = upper - 1;
        }
        sort(po, po + n, cmpy);
        for(int lower = 0; lower < n; ++ lower) {
            int upper = lower + 1;
            while(upper < n && po[lower].y == po[upper].y) {
                upper ++;
            }
            if((upper - lower) % 2)  flag = false;
            for(int i = lower; i < upper; i += 2) {
                if(i + 1 < upper) {
                    p[po[i].num].push_back(po[i + 1].num);
                    p[po[i + 1].num].push_back(po[i].num);
                    s[m].a = po[i].x; s[m].b = po[i].y; s[m ++].c = -1;
                    s[m].a = po[i + 1].x; s[m].b = po[i].y; s[m ++].c = -2;
                    ans += po[i + 1].x - po[i].x;
                }
            }
            lower = upper - 1;
        }
        memset(vis, false, sizeof(vis));
        dfs(0);
        for(int i = 0; i < n; ++ i) {
            if(!vis[i]) {
                flag = false;
            }
        }
        if(!flag) {
            puts("0");
            continue;
        }
        sort(s, s + m, cmps);
        memset(sum, 0, sizeof(sum));
        for(int i = 0; i < m; ++ i) {
            if(s[i].c >= 0) {
                //cout << s[i].b << " " << s[i].c << endl;
                if(query(s[i].b + 1, s[i].c - 1, 0, 20000, 1) > 0) {
                    flag = false;
                    break;
                }
            }
            else {
                if(s[i].c == -1)
                    update(s[i].b, 1, 0, 20000, 1);
                else
                    update(s[i].b, -1, 0, 20000, 1);
            }
        }
        if(!flag)
            puts("0");
        else
            printf("%d\n", ans);
    }
    return 0;
}

