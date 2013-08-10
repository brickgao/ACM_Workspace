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

char s[200], t[200];

bool chk(int x, int y, int l)
{
    for(int i = 0; i < l; i ++)
        if(s[i+x] == '2' && t[i+y] == '2')
            return false;
    return true;
}

int main()
{

    char a[200], b[200];
    while(scanf("%s%s",a,b) == 2)
    {
        int n = strlen(a);
        int m = strlen(b);
        if(n > m)
        {
            for(int i = 0; i < n; i ++)
                s[i] = a[i];
            for(int i = 0; i < m; i ++)
                t[i] = b[i];
        }
        else
        {
            for(int i = 0; i < m; i ++)
                s[i] = b[i];
            for(int i = 0; i < n; i ++)
                t[i] = a[i];
            _swap(n, m);
        }
        int ans = m + n;
        for(int i = 0; i < m; i ++)
            if(chk(0, i, m - i))
                get_min(ans, n + m - (m - i));
        for(int i = n - m; i < n; i ++)
            if(chk(i, 0, n - i))
                get_min(ans, n + m - (n - i));
        for(int i = 0; i <= n - m; i ++)
            if(chk(i, 0, m))
                get_min(ans, n);
        printf("%d\n",ans);
    }
    return 0;
}

