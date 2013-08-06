#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int mv[9][3]={{0,0},{0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}},n=10,m=10;
char str[30][30];
int num[30][30],map[30][30];
int f[140000];
int check(int x,int y)
{
	for(int k=0;k<9;k++)
		if(str[x+mv[k][0]][y+mv[k][1]]=='g')
			return 0;
	return 1;
}
int getone(int k)
{
	int ans=0;
	while(k!=0)
	{
		ans+=(k&1);
		k>>=1;
	}
	return ans;
}
int main()
{
	int casenum;
	scanf("%d",&casenum);
	while(casenum--)
	{
		for(int i=1;i<=n;i++)
			scanf("%s",str[i]+1);
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				map[i][j]=check(i,j);
		int NOW=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(str[i][j]=='e')
					num[i][j]=NOW++;
		if(NOW==0)
		{
			puts("0 0");
			continue;
		}
		memset(f,127,sizeof(f));
		int tag=f[0];
		f[0]=0;
		for(int sta=0;sta<=(1<<NOW)-1;sta++)
		{
			if(f[sta]==tag)
				continue;
			for(int i=1;i<=n;i++)
				for(int j=1;j<=m;j++)
					if(map[i][j])
					{
						int newsta=sta;
						for(int k=0;k<9;k++)
						{
							int x=i+mv[k][0],y=j+mv[k][1];
							if(str[x][y]=='e')
								newsta|=(1<<num[x][y]);
						}
						f[newsta]=min(f[newsta],f[sta]+1);
					}
		}
		int MAX=0,ans=0;
		for(int sta=0;sta<=(1<<NOW)-1;sta++)
		{
			if(f[sta]==tag)
				continue;
			if(getone(sta)>MAX)
			{
				MAX=getone(sta);
				ans=f[sta];
			}
			if(getone(sta)==MAX && f[sta]<ans)
			{
				MAX=getone(sta);
				ans=f[sta];
			}
		}
		printf("%d %d\n",MAX,ans);
	}
	return 0;
}

