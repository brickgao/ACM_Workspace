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
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int n;
int rec[6010];
int dp[6010][2];
vector <int> p[6010];
vector <int> tp[6010];

void dfs(int pre, int u) {
    for(int i = 0; i < SZ(p[u]); ++ i) {
        int v = p[u][i];
        if(v != pre) {
            dfs(u, v);
            dp[u][1] += dp[v][0];
            dp[u][0] += max(dp[v][1], dp[v][0]);
        }
    }
    dp[u][1] += rec[u];
    //cout << u << " " << dp[u][0] << " " << dp[u][1] << endl;
}

int get_root(int pre, int u) {
    int res = u;
    for(int i = 0; i < SZ(tp[u]); ++ i) {
        int v = tp[u][i];
        if(v != pre) {
            res = get_root(u, v);
        }
    }
    return res;
}

int main() {
    while(scanf("%d", &n) != EOF) {
        memset(dp, 0, sizeof(dp));
        for(int i = 0; i < 6010; ++ i)  p[i].clear(), tp[i].clear();
        for(int i = 1; i <= n; ++ i) scanf("%d", &rec[i]);
        while(1) {
            int u, v;
            scanf("%d%d", &u, &v);
            if(u == 0 && v == 0)    break;
            //cout << u << " " << v << endl;
            p[v].push_back(u);
            tp[u].push_back(v);
        }
        int root = get_root(-1, 1);
        dfs(-1, root);
        printf("%d\n", max(dp[root][1], dp[root][0]));
    }
    return 0;
}

