//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

template <int SIZE,int YA_COUNT>
class int128
{
	private:
		int val[SIZE+2],ya;
		char form[10];
	public:
		int128(int x=0)
		{
			memset(val,0,sizeof(val));
			ya=1;
			for(int i=1;i<=YA_COUNT;i++) ya*=10;
			sprintf(form,"%%0%d",YA_COUNT);	
			int p=0;
			while(x!=0)
			{
				val[++p]=x%ya;
				x/=ya;	
			}
		}	
		int& operator [](int x)
		{
			return val[x];	
		}
		friend bool operator >(int128& a,int128 &b)
		{
			int i,la=0,lb=0;
			for(i=SIZE;i>=1;i--) if(a[i]!=0) {la=i;break;}
			for(i=SIZE;i>=1;i--) if(b[i]!=0) {lb=i;break;}
			if(la>lb) return 1;
			else if(la<lb) return 0;
			else 
			{
				for(i=la;i>=1;i--)
					if(a[i]>b[i]) return 1;
					else if(a[i]<b[i]) return 0;	
			}	
			return 0;
		}
		friend bool operator ==(int128& a,int128 &b)
		{
			int i,la=0,lb=0;
			for(i=SIZE;i>=1;i--) if(a[i]!=0) {la=i;break;}
			for(i=SIZE;i>=1;i--) if(b[i]!=0) {lb=i;break;}
			if(la!=lb) return 0;
			else 
			{
				for(i=la;i>=1;i--)
					if(a[i]!=b[i]) return 0;
			}	
			return 1; 	
		}
		friend int128 operator +(int128& a,int128& b)
		{
			int128 c;
			for(int i=1;i<=SIZE;i++)
			{
				c[i]=a[i]+b[i]+c[i-1]/a.ya;
				c[i-1]%=a.ya;	
			}	
			return c;
		}
		friend int128 operator -(int128& a,int128& b)
		{
			int128 c;
			for(int i=1;i<=SIZE;i++)
			{
				c[i]+=a[i]-b[i];
				if(c[i]<0)
				{
					c[i]+=a.ya;
					c[i+1]--;	
				}	
			}	
			return c;
		}
		friend int128 operator /(int128& a,int b)
		{
			int128 c=a;
			for(int i=SIZE;i>=1;i--)
			{
				c[i-1]+=c[i]%b*a.ya;
				c[i]/=b;
			}
			c[0]/=a.ya;
			return c;
		}
		friend int128 operator *(int128& a,int128& b)
		{
			int128 c;
			for(int i=1;i<=SIZE;i++)
			{
				for(int j=1;j<=SIZE;j++)
				{
					c[i+j-1]+=a[i]*b[j];	
				}	
			}	
			for(int i=2;i<=SIZE;i++)
			{
				c[i]+=c[i-1]/a.ya;
				c[i-1]%=a.ya;	
			}
			return c;
		}
		friend istream& operator >>(istream& in,int128& a)
		{
			memset(a.val,0,sizeof(a.val));	
			char buf[20005];
			in>>buf;
			int len=strlen(buf);
			for(int i=0;i<len;i++) a[(len-i+YA_COUNT-1)/YA_COUNT]=a[(len-i+YA_COUNT-1)/YA_COUNT]*10+buf[i]-'0';
			return in;
		}
		friend ostream& operator <<(ostream& out,int128& a)
		{
			int p=SIZE-1;
			while(p>1 && a[p]==0) p--;
			out<<a[p];
			for(p--;p>=1;p--)
			{
				char tmp[10];
				sprintf(tmp,"%d",a[p]);
				cout<<tmp;	
			}	
			return out;
		}
};
#define bint int128<21,5>

typedef struct matrix {
    unsigned int a[40][40];
    void clear() { memset(a, 0, sizeof(a));}
    matrix() {memset(a, 0, sizeof(a));}
} matrix;

int t;
bint n;
int m, mod;
matrix ma, ans;

matrix operator * (matrix &a, matrix &b) {
    matrix c;
    for(int i = 0; i < (1 << m); ++ i)
        for(int j = 0; j < (1 << m); ++ j) {
            for(int k = 0; k < (1 << m); ++ k) {
                c.a[i][j] += a.a[i][k] * b.a[k][j];
                c.a[i][j] %= mod;
            }
        }
    return c;
}

int main() {
    bint zero(0), one(1);
    scanf("%d", &t);
    for(int T = 0; T < t; ++ T) {
        if(T)   puts("");
        cin >> n >> m >> mod;
        ma.clear();
        ans.clear();
        for(int i = 0; i < (1 << m); ++ i)
            for(int j = 0; j < (1 << m); ++ j) {
                int tmp1 = i, tmp2 = j;
                int vis[6];
                memset(vis, 0, sizeof(vis));
                for(int k = 0; k < m; ++ k) {
                    if((tmp1 & 1) && (tmp2 & 1))
                        vis[k] = 1;
                    else if((tmp1 & 1) == 0 && (tmp2 & 1) == 0)
                        vis[k] = 2;
                    else
                        vis[k] = 0;
                    tmp1 >>= 1;
                    tmp2 >>= 1;
                }
                bool flag = true;
                for(int k = 0; k < m - 1; ++ k) {
                    if(vis[k] == vis[k + 1] && vis[k] != 0) {
                        flag = false;
                        break;
                    }
                }
                if(flag)    ma.a[i][j] = 1;
                else        ma.a[i][j] = 0;
            }
//        for(int i = 0; i < (1 << m); ++ i) {
//            for(int j = 0; j < (1 << m); ++ j)
//                cout << ma.a[i][j] << " ";
//            cout << endl;
//        }
        for(int i = 0; i < (1 << m); ++ i)
            ans.a[i][i] = 1;
        n = n - one;
        for(; n > zero; n = n / 2, ma = ma * ma)
            if(n[1] & 1)    ans = ans * ma;
        int res = 0;
        for(int i = 0; i < (1 << m); ++ i)
            for(int j = 0; j < (1 << m); ++ j)
                res = (res + ans.a[i][j]) % mod;
        printf("%d\n", res);
    }
    return 0;
}

