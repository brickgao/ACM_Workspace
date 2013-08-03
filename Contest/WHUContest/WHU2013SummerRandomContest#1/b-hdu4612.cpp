#pragma comment(linker, "/STACK:1024000000,1024000000")
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
int pre[2000005],last[200005],son[2000005],tot,dist[200005],color[200005],dfn[200005],low[200005],NOW,flag[2000005],tag[200005],head,tail,id[2000005];
int que[200005],n,m;
struct node
{
	int a,b;
}rec[1000005];
void add(int a,int b,int c)
{
	tot++;
	son[tot]=b;
	pre[tot]=last[a];
	id[tot]=c;
	last[a]=tot;
}
void add(int a,int b)
{
	tot++;
	son[tot]=b;
	pre[tot]=last[a];
	last[a]=tot;
}
void tarjan(int k,int father)
{
	dfn[k]=low[k]=++NOW;
    for(int x=last[k];x;x=pre[x])
    {
        if(!dfn[son[x]])
        {
			tag[son[x]]=id[x];
            tarjan(son[x],k);
            low[k]=min(low[k],low[son[x]]);    
        }            
        else
            if(tag[k]!=id[x]) low[k]=min(low[k],dfn[son[x]]);
    }
    if(tag[k] && dfn[k]==low[k])
		flag[tag[k]]=1;
}
void dfs(int k,int col)
{
	color[k]=col;
	//cout<<"fuck  "<<k<<" "<<col<<endl;
	for(int x=last[k];x;x=pre[x])
	{
		int tmp;
		if(x&1) tmp=x/2+1;
		else tmp=x/2;
		if(!flag[tmp] && !color[son[x]])
			dfs(son[x],col);
	}
}
int bfs(int k)
{
	que[head=tail=1]=k;
	tail++,flag[k]=1;
	int ans=0,MAX=0;
	while(head<tail)
	{
		int p=que[head++];
		for(int x=last[p];x;x=pre[x])
			if(!flag[son[x]])
			{
				flag[son[x]]=1;
				que[tail++]=son[x];
				dist[son[x]]=dist[p]+1;
				if(dist[son[x]]>MAX)
				{
					MAX=dist[son[x]];
					ans=son[x];
				}
			}
	}
	return ans;
}
int main()
{
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(n==0 && m==0)
			break;
		memset(last,0,sizeof(last));
		tot=0;NOW=0;
		memset(color,0,sizeof(color));
		memset(flag,0,sizeof(flag));
		memset(dfn,0,sizeof(dfn));
		memset(tag,0,sizeof(tag));
		memset(low,0,sizeof(low));
		for(int i=1;i<=m;i++)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			add(a,b,i);
			add(b,a,i);
			rec[i].a=a,rec[i].b=b;
		}
		for(int i=1;i<=n;i++)
			if(!dfn[i])
				tarjan(i,0);
		int blocks=0;
		for(int i=1;i<=n;i++)
			if(!color[i])
				dfs(i,++blocks);
		memset(last,0,sizeof(last));
		tot=0;
		int old=0;
		for(int i=1;i<=m;i++)
		{
			if(flag[i])
			{
				old++;
				//cout<<"add  "<<color[rec[i].a]<<" "<<color[rec[i].b]<<endl;
				add(color[rec[i].a],color[rec[i].b]);
				add(color[rec[i].b],color[rec[i].a]);
			}
		}
		memset(flag,0,sizeof(flag));
		memset(dist,0,sizeof(dist));
		int a=bfs(1);
		memset(dist,0,sizeof(dist));
		memset(flag,0,sizeof(flag));
		int b=bfs(a);
		//cout<<old<<" "<<dist[b]<<endl;
		//cout<<a<<" "<<b<<" "<<dist[b]<<endl;
		printf("%d\n",old-dist[b]);
	}
	return 0;
}

