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

int k;
LL dp[35];

int main() {
    dp[0] = 1, dp[1] = 1, dp[2] = 2;
    for(int i = 3; i <= 30; ++ i) {
        for(int j = 0; j < i; ++ j) {
            dp[i] += dp[j] * dp[i - 1 - j];
        }
    }
    while(scanf("%d", &k) != EOF) {
        printf("%I64d %d\n", dp[k], k + 1);
    }
    return 0;
}

