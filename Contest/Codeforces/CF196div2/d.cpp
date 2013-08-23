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

int n, m, d;
int ans = 0;
vector <int> p[100010];
bool is[100010];
bool vis[100010];
int f[100010][2];

inline int get_max(int cmp1, int cmp2) {
    if(cmp1 > cmp2) return cmp1;
    else            return cmp2;
}

void dfs(int u) {
    vis[u] = true;
    if(is[u])    f[u][0] = 0;
    else        f[u][0] = -1;
    int ret = -1;
    for(int i = 0; i < SZ(p[u]); ++ i) {
        int v = p[u][i];
        if(!vis[v]) {
            dfs(v);
            if(f[v][0] != -1)
                ret = get_max(ret, f[v][0] + 1);
        }
    }
    f[u][0] = get_max(ret, f[u][0]);
}

void dp(int u) {
    vis[u] = true;
    int max1 = -1, max2 = -1;
    int rec1 = -1;
    if(f[u][1] > max1) {
        max1 = f[u][1];
        rec1 = u;
    }
    vector <int> nxt;
    nxt.clear();
    for(int i = 0; i < SZ(p[u]); ++ i) {
        int v = p[u][i];
        if(!vis[v]) {
            nxt.push_back(v);
            if(f[v][0] != -1 && f[v][0] + 1 > max1) {
                max2 = max1;
                max1 = f[v][0] + 1;
                rec1 = v;
                continue;
            }
            if(f[v][0] != -1 && f[v][0] + 1 > max2) {
                max2 = f[v][0] + 1;
            }
        }
    }
    //cout << u << " " << max1 << " " << max2 << " " << rec1 << endl;
    for(int i = 0; i < SZ(nxt); ++ i) {
        int v = nxt[i];
        if(v != rec1) {
            if(max1 != -1)
                f[v][1] = max1 + 1;
            else
                f[v][1] = -1;
        }
        else {
            if(max2 != -1)
                f[v][1] = max2 + 1;
            else
                f[v][1] = -1;
        }
    }
    for(int i = 0; i < SZ(nxt); ++ i)
        dp(nxt[i]);
}

int main() {
    memset(is, false, sizeof(is));
    scanf("%d%d%d", &n, &m, &d);
    for(int i = 0; i <= n; ++ i)    p[i].clear();
    for(int i = 0; i < m; ++ i) {
        int tmp;
        scanf("%d", &tmp);
        is[tmp] = true;
    }
    for(int i = 0; i < n - 1; ++ i) {
        int u, v;
        scanf("%d%d", &u, &v);
        p[u].push_back(v);
        p[v].push_back(u);
    }
    memset(vis, false, sizeof(vis));
    dfs(1);
    if(is[1])   f[1][1] = 0;
    else        f[1][1] = -1;
    memset(vis, false, sizeof(vis));
    dp(1);
    //for(int i = 1; i <= n; ++ i)    cout << f[i][0] << " " << f[i][1] << endl;
    for(int i = 1; i <= n; ++ i) {
        int tmp = get_max(f[i][1], f[i][0]);
        if(tmp != -1 && tmp <= d)   ++ ans;
    }
    printf("%d\n", ans);
    return 0;
}

