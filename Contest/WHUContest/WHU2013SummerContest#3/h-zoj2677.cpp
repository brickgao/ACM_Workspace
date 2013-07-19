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
const int MAXN = 100010;
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct Line {
    int u, v, c, num;
    bool operator < (const Line &cmp) const {
        return c  > cmp.c;
    }
} Line;

LL s;
Line l[MAXN];
bool vis[MAXN];
int parent[MAXN], q;
int rank[MAXN];
int n, m;

void makeset(int n) {
    for(int i = 1; i <= n; ++ i) {
        parent[i] = i;
        rank[i] = 0;
    }
}

int getparent(int x) {
    if(parent[x] == x)
        return x;
    else {
        parent[x] = getparent(parent[x]);
        return parent[x];
    }
}

void unionset(int x, int y) {
    if(rank[x] > rank[y])
        parent[y] = x;
    else {
        parent[x] = y;
        if(rank[x] == rank[y])
            ++ rank[y];
    }
}

void MST() {
    int cnt;
    memset(vis, false, sizeof(vis));
    sort(l, l + m);
    makeset(n);
    cnt = 0;
    for(int i = 0; i < m; ++ i) {
        int x = getparent(l[i].u);
        int y = getparent(l[i].v);
        if(x != y) {
            unionset(x, y);
            ++ cnt;
            vis[i] = true;
            if(cnt == n - 1)  break;
        }
    }
}

int main() {
    bool flag = false;
    while(scanf("%d%d%lld", &n, &m, &s) != EOF) {
        if(flag)    puts("");
        flag = true;
        for(int i = 0; i < m; ++ i) {
            scanf("%d%d%d", &l[i].u, &l[i].v, &l[i].c);
            l[i].num = i + 1;
        }
        MST();
        vector <int> ans;
        for(int i = m - 1; i >= 0; -- i) {
            if(s < l[i].c)  break;
            if(!vis[i]) {
                ans.push_back(l[i].num);
                s -= l[i].c;
            }
        }
        sort(ans.begin(), ans.end());
        printf("%d\n", SZ(ans));
        for(int i = 0; i < SZ(ans); ++ i) {
            if(i)   printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}

