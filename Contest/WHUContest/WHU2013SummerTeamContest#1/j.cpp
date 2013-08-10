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

int main()
{
    char s[200];
    while(scanf("%s",s) == 1)
    {
        int n = strlen(s);
        bool jv = false;
        bool cp = false;
        bool tag = false;
        for(int i = 0; i < n; i ++)
        {
            if(s[i] == '_')
                cp = true;
            else if(s[i] <= 'Z')
                jv = true;
            if(i && s[i] == '_' && s[i-1] == '_')
                tag = true;
        }
        if(cp && jv || tag)
        {
            puts("Error!");
            continue;
        }
        if(s[0] == '_' || s[0] <= 'Z' || s[n-1] == '_')
        {
            puts("Error!");
            continue;
        }
        if(!jv && !cp)
        {
            puts(s);
            continue;
        }
        if(jv)
        {
            //puts("JAVA");
            for(int i = 0; i < n; i ++)
                if(s[i] <= 'Z')
                    printf("_%c",s[i] + 32);
                else printf("%c",s[i]);
            puts("");
        }
        if(cp)
        {
            //puts("CPP");
            for(int i = 0; i < n; i ++)
                if(s[i] == '_')
                {
                    printf("%c",s[i+1] - 32);
                    i ++;
                }
                else printf("%c",s[i]);
            puts("");
        }
    }
    return 0;
}

