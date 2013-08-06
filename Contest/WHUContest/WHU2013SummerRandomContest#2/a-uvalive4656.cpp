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
int g, n;
int m[40];
double c[40][40];
double dp[40][40];

double gao(int x, int y) {
    double res = c[x][y];
    for(int i = 0; i < y; ++ i)
        res /= (double)n;
    return res;
}

int main() {
    memset(c, 0, sizeof(c));
    for(int i = 0; i <= 35; i ++) {
        c[i][0] = c[i][i] = 1.0;
        for(int j = 1; j < i; j ++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
    while(scanf("%d", &t) != EOF) {
        int caseno = 1;
        while(t --) {
            memset(dp, 0, sizeof(dp));
            scanf("%d%d", &g, &n);
            for(int i = 1; i <= n; ++ i) scanf("%d", &m[i]);
            dp[0][0] = 1;
            for(int i = 1; i <= n; ++ i)
                for(int j = 0; j <= g; ++ j)
                    for(int k = m[i]; k <= g - j; ++ k) {
                        dp[i][j + k] += dp[i - 1][j] * gao(g - j, k);
                    }
            printf("Case #%d: %.6lf\n", caseno ++, dp[n][g] * 100.0);
        }
    }
    return 0;
}

