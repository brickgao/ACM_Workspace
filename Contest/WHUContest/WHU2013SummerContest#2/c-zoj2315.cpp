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

int t;
int n;
vector <int> p[500010];
int dp[500010][2];
int rec[500010];
vector <int> way;

void dfs(int pre, int u) {
    int tmp1 = - maxint, tmp2 = 0, r = -1;
    for(int i = 0; i < SZ(p[u]); ++ i) {
        int v = p[u][i];
        if(v != pre) {
            dfs(u, v);
            dp[u][1] += dp[v][0];
            if(tmp1 < dp[v][1] - dp[v][0]) {
                tmp1 = dp[v][1] - dp[v][0];
                r = v;
            }
            tmp2 += dp[v][0];
        }
    }
    if(tmp2 < tmp2 + tmp1 && r != -1) {
        rec[r] = 1;
    }
    dp[u][0] += max(tmp2, tmp2 + tmp1);
    if(u != 1)
        dp[u][1] += 1000;
}

void get_way(int pre, int u, int m) {
    if(m == 1)  way.push_back(u);
    for(int i = 0; i < SZ(p[u]); ++ i) {
        int v = p[u][i];
        if(v != pre) {
            if(m == 0) {
                if(rec[v] == 1)
                    get_way(u, v, 1);
                else
                    get_way(u, v, 0);
            }
            else {
                get_way(u, v, 0);
            }
        }
    }
}

int main() {
    while(scanf("%d", &t) != EOF) {
        for(int T = 0; T < t; ++ T) {
            memset(dp, 0, sizeof(dp));
            memset(rec, -1, sizeof(rec));
            if(T)   puts("");
            way.clear();
            scanf("%d", &n);
            for(int i = 0; i <= n; ++ i)    p[i].clear();
            for(int i = 2; i <= n; ++ i) {
                int u;
                scanf("%d", &u);
                p[u].push_back(i);
            }
            dfs(-1, 1);
            //for(int i = 0; i <= n; ++ i)    cout << dp[i][0] << " " << dp[i][1] << endl;
            get_way(-1, 1, 0);
            sort(way.begin(), way.end());
            printf("%d\n", dp[1][0]);
            for(int i = 0; i < SZ(way); ++ i) {
                if(i)
                    printf(" ");
                printf("%d", way[i]);
            }
            printf("\n");
        }
    }
    return 0;
}

