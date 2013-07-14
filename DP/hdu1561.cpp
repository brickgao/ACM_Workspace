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

int m, n;
int rec[210];
int dp[210][210];
vector <int> p[210];

void dfs(int pre, int u) {
    for(int i = 0; i < SZ(p[u]); ++ i) {
        int v = p[u][i];
        if(v != pre) {
            dfs(u, v);
            for(int j = m + 1; j >= 2; -- j)
                for(int k = j - 1; k >= 1; -- k)
                    if(dp[v][k] != -1 && dp[u][j - k] != -1)
                        dp[u][j] = max(dp[u][j], dp[u][j - k] + dp[v][k]);
        }
    }
}

int main() {
    while(scanf("%d%d", &n, &m) != EOF && n != 0 && m != 0) {
        for(int i = 0; i < 210; ++ i)   p[i].clear();
        for(int i = 1; i <= n; ++ i) {
            int a, b;
            scanf("%d%d", &a, &b);
            rec[i] = b;
            p[a].push_back(i);
        }
        memset(dp, -1, sizeof(dp));
        for(int i = 0; i <= n; ++ i) {
            dp[i][0] = 0;
            dp[i][1] = rec[i];
        }
        dfs(-1, 0);
        printf("%d\n", dp[0][m + 1]);
    }
    return 0;
}

