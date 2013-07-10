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
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int n, m, k;
vector <int> p[MAXN];
int low[MAXN], dfa[MAXN];
int mat[MAXN][MAXN];
int s[MAXN], top;
bool instack[MAXN], vis[MAXN];

void Tarjan(int u, int pre, int depth) {
    low[u] = dfa[u] = depth;
    s[top ++] = u;
    instack[u] = true;
    for(int i = 0; i < SZ(p[u]); ++ i) {
        int v = p[u][i];
        if(v == pre && mat[u][v] > 1) {
            if(mat[u][v] % 2 == 0)
                vis[u] = true;
            continue;
        }
        if(!dfa[v]) {
            Tarjan(v, u, depth + 1);
            low[u] = min(low[u], low[v]);
        }
        else if(v != pre && instack[v]) {
            low[u] = min(low[u], dfa[v]);
        }
    }
    if(dfa[u] == low[u]) {
        int cnt = 1;
        top --;
        while(s[top] != u) {
            vis[s[top --]] = true;
            cnt ++;
        }
        if(cnt && (cnt & 1))
            vis[s[top + 1]] = false;
    }
    return;
}

int getsg(int u, int pre) {
    int res = 0;
    for(int i = 0; i < SZ(p[u]); ++ i) {
        int v = p[u][i];
        if(!vis[v] && v != pre)
            res ^= (1 + getsg(v, u));
    }
    return res;
}

int main() {
    while(scanf("%d", &n) != EOF) {
        int ans = 0;
        for(int i = 0; i < n; ++ i) {
            top = 0;
            memset(low, 0, sizeof(low));
            memset(dfa, 0, sizeof(dfa));
            memset(mat, 0, sizeof(mat));
            memset(vis, false, sizeof(vis));
            memset(instack, false, sizeof(instack));
            scanf("%d%d", &m, &k);
            for(int j = 0; j <= m; ++ j)    p[j].clear();
            for(int j = 0; j < k; j ++) {
                int u, v;
                scanf("%d%d", &u, &v);
                mat[u][v] ++;
                mat[v][u] ++;
                p[u].push_back(v);
                p[v].push_back(u);
            }
            Tarjan(1, -1, 1);
            ans ^= getsg(1, -1);
        }
        if(ans != 0)
            puts("Sally");
        else
            puts("Harry");
    }
    return 0;
}

