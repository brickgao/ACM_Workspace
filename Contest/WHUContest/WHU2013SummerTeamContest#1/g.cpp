#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <list>
#define out(v) cout << #v << ":" << (v) << endl
#define flin freopen("in.txt","r",stdin)
#define flout freopen("out.txt","w",stdout)
#define pb push_back
#define PI acos(-1.0)
using namespace std;
typedef long long lint;
const int inf = 1e9 + 7;
const double eps = 1e-8;
inline int sgn(const double x) {return (x > eps) - (x < -eps);}
template <class T> bool get_max(T &a, const T b) {return a < b ? a = b, true : false;}
template <class T> bool get_min(T &a, const T b) {return a > b ? a = b, true : false;}
template <class T> void _swap(T &a, T &b) {T t = a; a = b; b = t;}
double _fabs(double x)
{
    if(sgn(x) < 0) x = -x;
    return x;
}
bool u[2020];

int main()
{
    int n, m;
    while(scanf("%d%d",&n,&m) == 2)
    {
        double ans = 0;
        memset(u, false, sizeof(u));
        for(int i = 0; i < n; i ++)
        {
            double x = 9999999999.0;
            int p;
            for(int j = 0; j < m + n; j ++)
                if(!u[j] && get_min(x, _fabs(10000.0 * i / n - 10000.0 * j/ (n + m))))
                    p = j;
            u[p] = true;
            ans += x;
        }
        printf("%.6lf \n",ans);
    }
    return 0;
}

