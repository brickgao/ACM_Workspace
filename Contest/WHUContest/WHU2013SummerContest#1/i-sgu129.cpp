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
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int m, n;
LL dp[10][1 << 10];

void dfs(int f, int x, int y, int a, int b, int p) {
    //cout << f << " " << x << " " << y << " " << a << " " << b << " " << p << endl;
    if(p == m) {
        if(a == 0 && b == 0)    dp[f + 1][y] += dp[f][x];
        return;
    }
    if(b == 0) {
        if(a == 0) {
            dfs(f, x << 1, (y << 1) | 1, 0, 0, p + 1);
            dfs(f, x << 1, (y << 1) | 1, 1, 0, p + 1);
            dfs(f, x << 1, (y << 1) | 1, 0, 1, p + 1);
        }
        dfs(f, (x << 1) + 1 - a, (y << 1) | 1, 0, 1, p + 1);
        dfs(f, (x << 1) + 1 - a, (y << 1) | 1, 1, 1, p + 1);
    }
    if(a == 0)  dfs(f, x << 1, (y << 1) | b, 1, 1, p + 1);
    dfs(f, (x << 1) + 1 - a, (y << 1) | b, 0, 0, p + 1);
}

int main() {
    while(scanf("%d%d", &m, &n) != EOF) {
        memset(dp, 0, sizeof(dp));
        if(n < m)   swap(n, m);
        dp[0][(1 << m) - 1] = 1;
        for(int i = 0; i < n; ++ i) {
            dfs(i, 0, 0, 0, 0, 0);
        }
        printf("%lld\n", dp[n][(1 << m) - 1]);
    }
    return 0;
}

