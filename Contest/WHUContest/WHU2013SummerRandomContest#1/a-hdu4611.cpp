#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
__int64 gcd(__int64 a,__int64 b)
{
	if(a<b)
		swap(a,b);
	if(b==0)
		return a;
	return gcd(b,a%b);
}
__int64 abs(__int64 k)
{
	if(k<0)
		return -k;
	return k;
}
__int64 get(__int64 n,__int64 a,__int64 b)  // n balls 
{
	__int64 ans=0,pa=a-1,pb=b-1;
	while(pa<n && pb<n)
	{
		if(pb<pa)
		{
			while(pb+b<=pa)
			{
				ans+=b*(abs((pb+b)%a-(pb+b)%b));
				pb+=b;
			}
			__int64 tmpa=pa%a,tmpb=pa%b;
			ans+=abs(pa-pb)*abs(tmpb-tmpa);
			pb+=b;
		}
		else
		{
			__int64 tmpa=pb%a,tmpb=pb%b;
			ans+=abs(pa-pb)*abs(tmpb-tmpa);
			pa+=a;
		}
		//cout<<"fuck  "<<ans<<endl;
	}
	if(pa<n)
	{
		while(pa+a<n)
		{
			ans+=a*abs((pa+a)%a-(pa+a)%b);
			pa+=a;
		}
		if(pa<n) ans+=(n-pa-1)*abs(n%a-n%b);
	}
	if(pb<n)
	{
		while(pb+b<n)
		{
			ans+=b*abs((pb+b)%a-(pb+b)%b);
			pb+=b;
		}
		if(pb<n) ans+=(n-pb-1)*abs(n%a-n%b);
	}
	return ans;
}
int main()
{
	int casenum;
	scanf("%d",&casenum);
	while(casenum--)
	{
		__int64 n,a,b;
		cin>>n>>a>>b;
		if(a<b)
			swap(a,b);
		__int64 lcm=(a*b)/gcd(a,b);
		cout<<(n/lcm)*get(lcm,a,b)+get(n%lcm,a,b)<<endl;
	}
	return 0;
}

