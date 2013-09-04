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

double dp[1010][1010];
int n, s;

int main() {
    while(scanf("%d%d", &n, &s) != EOF) {
        for(int i = 0; i < 1010; ++ i)
            for(int j = 0; j < 1010; ++ j)
                dp[i][j] = 0.0;
        for(int i = n; i >= 0; -- i)
            for(int j = s; j >= 0; -- j) {
                if(i == n && j == s)    continue;
                double tmp = n * s - i * j;
                dp[i][j] = dp[i + 1][j] * j * (n - i) + dp[i][j + 1] * (s - j) * i + dp[i + 1][j + 1] * (n - i) * (s - j) + n * s;
                dp[i][j] /= tmp;
            }
        printf("%.4lf\n", dp[0][0]);
    }
    return 0;
}

