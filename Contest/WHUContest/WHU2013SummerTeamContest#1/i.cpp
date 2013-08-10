#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <string>
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
struct node
{
    int a[40];
    void SORT(){sort(a+1,a+1+a[0]);}
    bool operator==(const node& o)
    {
        if(a[0]!=o.a[0])
            return 0;
        for(int i =0;i<=a[0];i++)
            if(a[i]!=o.a[i])
                return 0;
        return 1;
    }
}src,map[200005];
double f[200000];
int num[200000],father[200000],n,m,total,mod=99997;
int getf(int k){if(k==father[k]) return k;return father[k]=getf(father[k]);}
int hash(node now)
{
	int ans=0;
	for(int i=1;i<=now.a[0];i++)
	{
        ans+=now.a[i]+now.a[i]*now.a[i]*now.a[i]*i*i;
        ans%=mod;
	}
	while(map[ans].a[0] && !(map[ans]==now))
        ans++;
	if(map[ans].a[0]==0)
        map[ans]=now;
	return ans;
}
double dp(node now)
{
	int k=hash(now);
	if(f[k] || now.a[0]==1)
        return f[k];
	double same=0.0;
	for(int i=1;i<=now.a[0];i++)
		for(int j=1;j<=i;j++)
			if(i==j) same+=(double)now.a[i]*(now.a[i]-1)/total/2.0;
			else
			{
				node next=now;
				next.a[i]+=next.a[j];
				swap(next.a[j],next.a[next.a[0]]);
				next.a[0]--;
				next.SORT();
				f[k]+=(double)now.a[i]*now.a[j]*dp(next)/total;
			}
	f[k]=(f[k]+1)/(1-same);
	return f[k];
}
int main()
{	while(scanf("%d %d",&n,&m)!=EOF)
    {
        int a,b;
        src.a[0]=0;
        memset(f,0,sizeof(f));
        memset(num,0,sizeof(num));
        for(int i = 0;i<99997;i++)
            map[i].a[0]=0;
        for(int i=1;i<=n;i++)
            father[i]=i;
        for(int i=1;i<=m;i++)
        {
            scanf("%d %d",&a,&b);
            father[getf(b)]=getf(a);
        }
        for(int i=1;i<=n;i++)
            num[getf(i)]++;
        for(int i=1;i<=n;i++)
            if(getf(i)==i)
                src.a[++src.a[0]]=num[i];
        total=n*(n-1)/2;
        if(dp(src)<1e-10) printf("0.000000\n");
        else printf("%.6lf\n",dp(src));
    }
	return 0;
}

