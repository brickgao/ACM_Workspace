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

int cash, N;
int dp[100010];
int v[200];

int main() {
    while(scanf("%d%d", &cash, &N) != EOF) {
        int t = 0;
        memset(dp, 0, sizeof(dp));
        dp[0] = 1;
        for(int i = 0; i < N; ++ i) {
            int n, d;
            scanf("%d%d", &n, &d);
            int k = 1;
            while(k < n) {
                v[t ++] = k * d;
                n -= k;
                k = k << 1;
            }
            if(n > 0)  v[t ++] = n * d;
        }
        for(int i = 0; i < t; ++ i)
            for(int j = cash - v[i]; j >= 0; -- j) {
                if(dp[j] == 1 && j + v[i] <= cash)  dp[j + v[i]] = 1;
            }
        int ans = cash;
        while(!dp[ans])  -- ans;
        printf("%d\n", ans);
    }
    return 0;
}

