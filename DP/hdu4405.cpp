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
const double p = 1.0 / 6.0;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int m, n;
int x, y;
double dp[100010];
int nxt[100010];

int main() {
    while(scanf("%d%d", &n, &m) != EOF) {
        if(m == 0 && n == 0)    break;
        for(int i = 0; i < 100010; ++ i)    dp[i] = 0.0;
        memset(nxt, -1, sizeof(nxt));
        for(int i = 0; i < m; ++ i) {
            scanf("%d%d", &x, &y);
            nxt[x] = y;
        }
        for(int i = n - 1; i >= 0; -- i) {
            if(nxt[i] != -1) {
                dp[i] = dp[nxt[i]];
                continue;
            }
            for(int j = 1; j <= 6; ++ j) {
                dp[i] += (dp[i + j] + 1) * p;
            }
        }
        printf("%.4lf\n", dp[0]);
    }
    return 0;
}

