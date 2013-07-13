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

int t, e, f, n;
int p[510], w[510];
int dp[10010];

int main() {
    while(scanf("%d", &t) != EOF) {
        for(int i = 0; i < t; ++ i) {
            for(int j = 0; j <= 10010; ++ j)    dp[j] = maxint;
            dp[0] = 0;
            scanf("%d%d%d", &e, &f, &n);
            for(int j = 0; j < n; ++ j) {
                scanf("%d%d", &p[j], &w[j]);
            }
            int mass = f - e;
            if(mass <= 0) {
                puts("This is impossible.");
                continue;
            }
            for(int j = 0; j <= mass; ++ j) {
                int minn = maxint;
                for(int k = 0; k < n; ++ k) {
                    int tmp = j - w[k];
                    if(tmp >= 0 && dp[tmp] != maxint) {
                        minn = min(dp[tmp] + p[k], minn);
                    }
                }
                if(minn != maxint)
                    dp[j] = min(minn, dp[j]);
            }
//            for(int j = 0; j <= 5; ++ j)
//                cout << dp[j] << " ";
//            cout << endl;
            if(dp[mass] != maxint)
                printf("The minimum amount of money in the piggy-bank is %d.\n", dp[mass]);
            else
                puts("This is impossible.");
        }
    }
    return 0;
}

