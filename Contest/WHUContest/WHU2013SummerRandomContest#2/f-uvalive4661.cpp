#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<algorithm>
#include<iostream>
#include<string> 
#include<cmath>

#define rept(i,a,b) for (i=(a);i<=(b);i++)
#define repd(i,a,b) for (i=(a);i>=(b);i--)
#define clr(a) memset(a,0,sizeof(a))
#define clrs(a,b) memset(a,b,sizeof(a))

using namespace std;

struct sic
{
	double r;
	int b;
};
int co,co2,times,q,cnt,i,j,k,tmp,n,m,ans;
int cntarr[60],bingo[60],pc[60];
struct sic a;
double p[60];


void mul(double op)
{
	a.r=a.r*op;
	while (a.r>=10)
	{
		a.r=a.r/10;
		a.b++;
	}
	while (a.r<1)
	{
		a.r=a.r*10;
		a.b--;
	}

}

void divs(double op)
{
	a.r=a.r/op;
	while (a.r<1)
	{
		a.r=a.r*10;
		a.b--;
	}
}


int main()
{
	
	scanf("%d",&times);
	rept(co,1,times)
	{
		printf("Test Case #%d:\n",co);
		
		scanf("%d",&n);
		rept(i,1,n)
			scanf("%lf",&p[i]);
		scanf("%d",&q);
		rept(co2,1,q)
		{
			scanf("%d",&m);
			rept(i,1,m)
				scanf("%d",&bingo[i]);
			
			a.r=1;
			a.b=0;
			rept(i,1,m)
				mul(p[bingo[i]]);
			rept(i,1,m)
				mul(i);
				
			clr(pc);
			cnt=0;
			rept(i,1,m)
				pc[bingo[i]]++;
				
			rept(i,1,n)
				if (pc[i]>1)
				{
					cnt++;
					cntarr[cnt]=pc[i];
				}
			
			rept(i,1,cnt)
				rept(j,1,cntarr[i])
					divs(j);
			
			printf("%.5lf",a.r);
			printf(" x 10^%d\n",a.b);
		}
	}
	return 0;
}

		
			

