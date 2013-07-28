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
int n, m;
int mx;
int map[110][110], stk[110][110];
int tt[110], dp[110], ans[110];

void dfs(int ns, int dep) {
    if(ns == 0) {
        if(dep > mx) {
            mx = dep;
            for(int i = 1; i <= dep; ++ i)
                ans[i] = tt[i];
        }
        return;
    }
    for(int i = 0; i < ns; ++ i) {
        int k = stk[dep][i], cnt = 0;
        if(dep + n - k <= mx)   return;
        if(dep + dp[k] <= mx)   return;
        for(int j = i + 1; j < ns; ++ j) {
            int p = stk[dep][j];
            if(map[k][p])
                stk[dep + 1][cnt ++] = p;
        }
        tt[dep + 1] = k;
        dfs(cnt, dep + 1);
    }
}

int clique() {
    mx = 0;
    for(int i = n; i >= 1; -- i) {
        int cnt = 0;
        for(int j = i + 1; j <= n; ++ j)
            if(map[i][j])
                stk[1][cnt ++] = j;
        tt[1] = i;
        dfs(cnt, 1);
        dp[i] = mx;
    }
    return mx;
}

int main() {
    scanf("%d", &t);
    while(t --) {
        scanf("%d%d", &n, &m);
        for(int i = 0; i < 110; ++ i)
            for(int j = 0; j < 110; ++ j)
                map[i][j] = 1;
        for(int i = 0; i < m; ++ i) {
            int x, y;
            scanf("%d%d", &x, &y);
            map[x][y] = map[y][x] = 0;
        }
        int num = clique();
        printf("%d\n", num);
        for(int i = 1; i <= num; ++ i) {
            if(i != 1)   printf(" ");
            printf("%d", ans[i]);
        }
        printf("\n");
    }
    return 0;
}

