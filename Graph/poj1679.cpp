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
const int MAXN = 110;
const int INF = 0x7FFFFFFF;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct edge {
    int nxt, w, v;
    int op;
    bool flag;
} edge;

int ans;
int t, n, m;
int head1[MAXN], head2[MAXN], MST[MAXN], f[MAXN], rec[MAXN];
edge e[MAXN * MAXN], ne[MAXN * MAXN];
int edgenum1, edgenum2, sum;

inline void addedge(int head[], edge ed[], int &edgenum, int u, int v, int w) {
    ed[edgenum].nxt = head[u];
    ed[edgenum].flag = false;
    ed[edgenum].v = v;
    ed[edgenum].w = w;
    ed[edgenum].op = edgenum + 1;
    head[u] = edgenum;
    ++ edgenum;
    ed[edgenum].nxt = head[v];
    ed[edgenum].flag = false;
    ed[edgenum].v = u;
    ed[edgenum].w = w;
    ed[edgenum].op = edgenum - 1;
    head[v] = edgenum;
    ++ edgenum;
}

void prim() {
    for(int i = 1; i <= n; ++ i)    MST[i] = INF;
    for(int i = 1; ; ) {
        MST[i] = - INF;
        for(int j = head1[i]; j != -1; j = e[j].nxt) {
            int v = -1;
            if(e[j].w < MST[v = e[j].v]) {
                MST[v] = e[j].w;
                rec[v] = e[j].op;
            }
        }
        int Minn = INF;
        i = 0;
        for(int j = 1; j <= n; ++ j)
            if(MST[j] != - INF && MST[j] < Minn) {
                Minn = MST[j];
                i = j;
            }
        if(i == 0)
            break;
    }
    for(int i = 2; i <= n; ++ i) {
        sum += e[rec[i]].w;
        int v = e[rec[i]].v;
        e[rec[i]].flag = e[e[rec[i]].op].flag = true;
        addedge(head2, ne, edgenum2, i, v, e[rec[i]].w);
    }
}

void dfs(int u) {
    for(int i = head2[u]; i != -1; i = ne[i].nxt) {
        int v = ne[i].v;
        if(f[v] == - INF) {
            f[v] = f[u];
            if(ne[i].w > f[v])
                f[v] = ne[i].w;
            dfs(v);
        }
    }
}

void smst() {
    for(int i = 1; i <= n; ++ i) {
        for(int j = 1; j <= n; ++ j)    f[j] = - INF;
        ++ f[i];
        dfs(i);
        for(int j = head1[i]; j != -1; j = e[j].nxt) {
            int v = e[j].v;
            if(!e[j].flag) {
                int tmp = sum + e[j].w - f[v];
                if(tmp < ans)
                    ans = tmp;
            }
        }
    }
}

int main() {
    while(scanf("%d", &t) != EOF) {
        while(t --) {
            memset(head1, -1, sizeof(head1));
            memset(head2, -1, sizeof(head2));
            memset(rec, 0, sizeof(rec));
            edgenum1 = edgenum2 = 0;
            ans = INF;
            sum = 0;
            scanf("%d%d", &n, &m);
            for(int i = 0; i < m; ++ i) {
                int u, v, w;
                scanf("%d%d%d", &u, &v, &w);
                addedge(head1, e, edgenum1, u, v, w);
            }
            prim();
            smst();
            if(ans > sum)   printf("%d\n", sum);
            else            puts("Not Unique!");
        }
    }
    return 0;
}

