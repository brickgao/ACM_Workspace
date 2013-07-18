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

int t;
int m, n;
int rec[100010][2];
int sum[10010];

int main() {
    while(scanf("%d", &t) != EOF) {
        for(int T = 0; T < t; ++ T) {
            LL ans = 0;
            memset(sum, 0, sizeof(sum));
            scanf("%d%d", &n, &m);
            for(int i = 0; i < m; ++ i) {
                scanf("%d%d", &rec[i][0], &rec[i][1]);
                sum[rec[i][0]] ++; sum[rec[i][1]] ++;
            }
            for(int i = 0; i < m; ++ i) {
                ans += sum[rec[i][0]] + sum[rec[i][1]];
            }
            printf("%lld\n", ans);
            if(T != t - 1)  puts("");
        }
    }
    return 0;
}

