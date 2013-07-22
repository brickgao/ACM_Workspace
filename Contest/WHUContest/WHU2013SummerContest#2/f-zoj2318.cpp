//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const double eps = 1e-6;
const int maxnum = 350;
const int INF = 0x1fffffff;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct circle {
    double x, y, r;
} circle;

typedef struct Edge{
	int v, next;
	double w;
} Edge;

int t;
Edge node[maxnum * maxnum];
double dist[maxnum];
bool vis[maxnum];
int in[maxnum];
int nodenum, edgenum;
circle c[310];

inline int sgn(double x) {
    return (x > eps) - (x < -eps);
}

inline double dis(circle a, circle b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

void add(int u, int v, double cost) {
    ++ edgenum;
    node[edgenum].v = v;
    node[edgenum].w = cost;
    node[edgenum].next = node[u].next;
    node[u].next = edgenum;
}

bool spfa() {
    queue <int> q;
    memset(vis, 0, sizeof(vis));
    memset(in, 0, sizeof(in));
    for(int i = 1; i <= nodenum; ++ i) {
        q.push(i), vis[i] = true, in[i] = 0, dist[i] = 0.0;
    }
    while(!q.empty()) {
        int u = q.front(); q.pop();
        vis[u] = false;
        for(int son = node[u].next; son != - 1; son = node[son].next) {
            int v = node[son].v;
            double w = node[son].w;
            if(sgn(dist[v] - (dist[u] + w)) > 0) {
                dist[v] = dist[u] + w;
                if(!vis[v]) {
                    ++ in[v];
                    if(in[v] > nodenum) return false;
                    vis[v] = true;
                    q.push(v);
                }
            }
        }
    }
    return true;
}

int main() {
    while(scanf("%d", &t) != EOF) {
        for(int T = 0; T < t; ++ T) {
            if(T)   puts("");
            scanf("%d", &nodenum);
            edgenum = nodenum;
            for(int i = 1; i <= nodenum; ++ i)
                scanf("%lf%lf%lf", &c[i].x, &c[i].y, &c[i].r);
            scanf("%lf%lf%lf", &c[0].x, &c[0].y, &c[0].r);
            for(int i = 1; i <= nodenum; ++ i)
                c[i].x -= c[0].x, c[i].y -= c[0].y, c[i].r += c[0].r;
            c[0].r = c[0].x = c[0].y = 0.0;
            for(int i = 0; i < maxnum * maxnum; ++ i) {
                node[i].v = node[i].next = -1;
            }
            for(int i = 1; i <= nodenum; ++ i)
                for(int j = 0; j < i; ++ j) {
                    if(sgn(dis(c[i], c[j]) - (c[i].r + c[j].r)) >= 0)    continue;
                    bool flag = (c[i].x * c[j].y - c[j].x * c[i].y) >= 0;
                    double C = acos((c[i].x * c[j].x + c[i].y * c[j].y) / (dis(c[i], c[0]) * dis(c[j], c[0])));
                    add(i, j, flag ? C: -C);
                    add(j, i, !flag ? C: -C);
                }
            if(spfa())
                puts("YES");
            else
                puts("NO");
        }
    }
    return 0;
}

