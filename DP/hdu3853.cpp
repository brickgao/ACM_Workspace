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

int r, c;
double rec[1010][1010][3];
double dp[1010][1010];

int main() {
    while(scanf("%d%d", &r, &c) != EOF) {
        for(int i = 0; i < r; ++ i)
            for(int j = 0; j < c; ++ j)
                scanf("%lf%lf%lf", &rec[i][j][0], &rec[i][j][1], &rec[i][j][2]);
        memset(dp, 0, sizeof(dp));
        dp[r - 1][c - 1] = 0;
        for(int i = r - 1; i >= 0; -- i)
            for(int j = c - 1; j >= 0; -- j) {
                if(rec[i][j][0] == 1.0) continue;
                dp[i][j] = (dp[i][j + 1] * rec[i][j][1] + dp[i + 1][j] * rec[i][j][2] + 2.0) / (1 - rec[i][j][0]);
            }
        printf("%.3lf\n", dp[0][0]);
    }
    return 0;
}

