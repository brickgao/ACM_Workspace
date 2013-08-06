#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
int c[2005];
int gettime(char *str)
{
	//cout<<"fuck   "<<str<<endl;
	int h=(str[0]-'0')*10+(str[1]-'0');
	int m=(str[3]-'0')*10+(str[4]-'0');
	return h*60+m;
}
int main()
{
	int casenum;
	char str[105];
	scanf("%d",&casenum);
	while(casenum--)
	{
		memset(c,0,sizeof(c));
		int n;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("\n");
			gets(str);
			//cout<<str<<endl;
			int L=gettime(str);
			int R=gettime(str+6);
			//cout<<L<<" "<<R<<endl;
			for(int i=L;i<=R;i++)
				c[i]++;
		}
		int MAX=0,maxi;
		for(int i=0;i<1440;i++)
			if(c[i]>MAX)
			{
				MAX=c[i];
				maxi=i;
			}
		int L=maxi,R;
		for(int i=L;i<1440;i++)
		{
			if(c[i]==MAX) R=i;
			else break;
		}
		printf("%02d:%02d %02d:%02d\n",L/60,L%60,R/60,R%60);
	}
	return 0;
}

