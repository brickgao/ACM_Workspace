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

int n, m;
int a[110][110];
int dp[110];

int main() {
    while(scanf("%d%d", &n, &m) != EOF && n != 0 && m != 0) {
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= n; ++ i)
            for(int j = 1; j <= m; ++ j)
                scanf("%d", &a[i][j]);
        for(int i = 1; i <= n; ++ i)
            for(int j = m; j >= 0; -- j)
                for(int k = j; k >= 1; -- k)
                    dp[j] = max(dp[j], dp[j - k] + a[i][k]);
        printf("%d\n", dp[m]);
    }
    return 0;
}

