#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>
using namespace std;
map<pair<string,int> ,int> hash;
int mv[9][3]={{0,0},{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}},tag;
struct info
{
	string s;
	int len;
};
struct node
{
	int x,y;
	node(){}
	node(int x,int y):x(x),y(y){}
}que[100005];
char str[105][105],anss[105][105];
int flag[105][105],head,tail,tflag[105][105];
info bfs(int sx,int sy)
{
	int minx=sx,miny=sy,maxx=sx,maxy=sy;
	bool tmp[105][105];
	memset(tmp,0,sizeof(tmp));
	que[head=tail=1]=node(sx,sy); tail++;
	flag[sx][sy]=1;
	tmp[sx][sy]=1;
	while(head<tail)
	{
		node p=que[head++];
		for(int k=1;k<=8;k++)
		{
			int x=p.x+mv[k][0],y=p.y+mv[k][1];
			if(!flag[x][y] && str[x][y]=='1')
			{
				flag[x][y]=1;
				tmp[x][y]=1;
				minx=min(minx,x);
				miny=min(miny,y);
				maxx=max(maxx,x);
				maxy=max(maxy,y);
				que[tail++]=node(x,y);
			} 
		}
	}
	info ans;
	ans.s.clear();
	for(int i=minx;i<=maxx;i++)
		for(int j=miny;j<=maxy;j++)
		{
			if(tmp[i][j]) ans.s+=str[i][j];
			else ans.s+='0';
		}
	ans.len=maxy-miny+1;
	return ans;
}
info rotate(info k)
{
	int n=k.s.length()/k.len,m=k.len;
	char tmp[105][105];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			tmp[i][j]=k.s[(i-1)*m+j-1];
	char s[106][106];
	//swap(n,m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			s[j][n-i+1]=tmp[i][j];
	swap(n,m);
	info ans;
	ans.s.clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans.s+=s[i][j];
	ans.len=m;
	return ans;
}
info mir(info k)
{
	int n=k.s.length()/k.len,m=k.len;
	char tmp[105][105];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			tmp[i][j]=k.s[(i-1)*m+j-1];
	char s[106][106];
	for(int i=1;i<=n;i++) 
		for(int j=1;j<=m;j++)
			s[i][m-j+1]=tmp[i][j];
	info ans;
	ans.s.clear();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			ans.s+=s[i][j];
	ans.len=m;
	return ans;
}
int check(info k)
{
	int n=k.s.length()/k.len, m=k.len;
	if(hash[make_pair(k.s,m)])   //src
		return hash[make_pair(k.s,m)];
	info tmp=mir(k);   
	if(hash[make_pair(tmp.s,m)])  // mir
		return hash[make_pair(tmp.s,tmp.len)];
	tmp=rotate(k);   // rotate
	if(hash[make_pair(tmp.s,tmp.len)])
		return hash[make_pair(tmp.s,tmp.len)];
	tmp=mir(tmp);    //rotate mir
	if(hash[make_pair(tmp.s,tmp.len)])
		return hash[make_pair(tmp.s,tmp.len)];
	tmp=rotate(rotate(k)); // rotate rotate
	if(hash[make_pair(tmp.s,tmp.len)])
		return hash[make_pair(tmp.s,tmp.len)];
	tmp=mir(tmp);
	if(hash[make_pair(tmp.s,tmp.len)])   // rotate rotate mir
		return hash[make_pair(tmp.s,tmp.len)];
	tmp=rotate(rotate(rotate(k)));
	if(hash[make_pair(tmp.s,tmp.len)])
		return hash[make_pair(tmp.s,tmp.len)]; 
	tmp=mir(tmp);
	if(hash[make_pair(tmp.s,tmp.len)])
		return hash[make_pair(tmp.s,tmp.len)];
	tag++;
	hash[make_pair(k.s,k.len)]=tag;   //src
	tmp=mir(k);   
	hash[make_pair(tmp.s,tmp.len)]=tag;  // mir
	tmp=rotate(k);   // rotate
	hash[make_pair(tmp.s,tmp.len)]=tag;
	tmp=mir(tmp);    //rotate mir
	hash[make_pair(tmp.s,tmp.len)]=tag;
	tmp=rotate(rotate(k)); // rotate rotate
	hash[make_pair(tmp.s,tmp.len)]=tag;
	tmp=mir(tmp);	 // rotate rotate mir
	hash[make_pair(tmp.s,tmp.len)]=tag;  
	tmp=rotate(rotate(rotate(k)));
	hash[make_pair(tmp.s,tmp.len)]=tag;
	tmp=mir(tmp);
	hash[make_pair(tmp.s,tmp.len)]=tag;
	return tag;
}
char get(int k)
{
	if(k>=1 && k<=26)
		return 'A'+k-1;
	k-=26;
	return 'a'+k-1;
}
void fill(int sx,int sy,int ktag)
{
	que[head=tail=1]=node(sx,sy); tail++;
	anss[sx][sy]=get(ktag);
	while(head<tail)
	{
		node p=que[head++];
		for(int k=1;k<=8;k++)
		{
			int x=p.x+mv[k][0],y=p.y+mv[k][1];
			if(!tflag[x][y] && str[x][y]=='1')
			{
				tflag[x][y]=1;
				anss[x][y]=get(ktag);
				que[tail++]=node(x,y);
			} 
		}
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	while(1)
	{
		int ans=0;
		tag=0;
		hash.clear();
		memset(flag,0,sizeof(flag));
		memset(tflag,0,sizeof(tflag));
		memset(anss,0,sizeof(anss));
		memset(str,0,sizeof(str));
		for(int i=1;i<=n;i++)
			scanf("%s",str[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(str[i][j]=='1' && !flag[i][j])
				{
					info tmp=bfs(i,j);
					int pre=tag,now;
					now=check(tmp);
					fill(i,j,now);
					if(now>pre) 
						ans++;
				}
		printf("%d\n",ans);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(!anss[i][j])
					anss[i][j]='0';
		for(int i=1;i<=n;i++)
			printf("%s\n",anss[i]+1);
		scanf("%d %d",&n,&m);
		if(n==0 && m==0) break;
		else puts("");
	}
	return 0;
}

