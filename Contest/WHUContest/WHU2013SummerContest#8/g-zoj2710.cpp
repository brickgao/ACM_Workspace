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
const double eps = 1e-6;
inline int sgn(const double x) {return (x > eps) - (x < -eps);}
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct pnt{double x, y;} pnt;
typedef struct vct{double x, y;} vct;
typedef struct seg{pnt s, t;} seg;
const pnt o = {0.0, 0.0};

int n, c;
seg s[2];
double cost[210][2];
double dp[210][210];
int pre[210][210];
int rec[210];

vct operator - (pnt s, pnt t) {
    vct res = {t.x - s.x, t.y - s.y};
    return res;
}

seg operator ^ (pnt s, pnt t) {
    seg res = {s, t};
    return res;
}

double operator * (vct a, vct b) {
    return a.x * b.y - a.y * b.x;
}

double operator ^ (vct a, vct b) {
    return a.x * b.x + a.y * b.y;
}


double dis(pnt a, pnt b) {
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

double dis(pnt a, seg b) {
    double s = (b.t - b.s) * (a - b.s);
    double res = s / dis(b.s, b.t);
    if(sgn(res) == -1) {
        res = 0.0 - res;
    }
    return res;
}

void dfs(int u, int k) {
    if(u == 0)  return;
    rec[u] = pre[u][k] + 1;
    dfs(u - 1, k - pre[u][k]);
}

int main() {
    while(scanf("%d%d", &n, &c) != EOF) {
        for(int i = 0; i < 2; ++ i) {
            pnt tmp1, tmp2;
            scanf("%lf%lf%lf%lf", &tmp1.x, &tmp1.y, &tmp2.x, &tmp2.y);
            s[i] = tmp1 ^ tmp2;
        }
        for(int i = 1; i <= n; ++ i) {
            pnt tmp;
            double t;
            scanf("%lf%lf%lf", &tmp.x, &tmp.y, &t);
            cost[i][0] = dis(tmp, s[0]) * t;
            cost[i][1] = dis(tmp, s[1]) * t;
            //cout << cost[i][0] << " " << cost[i][1] << endl;
        }
        for(int i = 0; i <= n; ++ i)
            for(int j = 0; j <= n; ++ j)
                dp[i][j] = 0.0;
        for(int i = 1; i <= n; ++ i) {
            dp[i][0] = dp[i - 1][0] + cost[i][0];
            pre[i][0] = 0;
            //cout << pre[i][0] << " " << dp[i][0] << endl;
            for(int j = 1; j < i; ++ j) {
                if(dp[i - 1][j] + cost[i][0] <= dp[i - 1][j - 1] + cost[i][1]) {
                    dp[i][j] = dp[i - 1][j] + cost[i][0];
                    pre[i][j] = 0;
                }
                else {
                    dp[i][j] = dp[i - 1][j - 1] + cost[i][1];
                    pre[i][j] = 1;
                }
                //cout << pre[i][j] << " " << dp[i][j] << endl;
            }
            dp[i][i] = dp[i - 1][i - 1] + cost[i][1];
            pre[i][i] = 1;
        }
        int minn = -1;
        for(int i = max((n - c + 1) / 2, 0); i <= min((n + c) / 2, n); ++ i) {
            if(minn == -1 || dp[n][i] <= dp[n][minn])
                minn = i;
        }
        dfs(n, minn);
        for(int i = 1; i <= n; ++ i) {
            if(i != 1)  printf(" ");
            printf("%d", rec[i]);
        }
        puts("");
        puts("");
    }
    return 0;
}

