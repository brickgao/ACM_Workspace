#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
#define pb push_back
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
struct node
{
    node *c[26], *fail;
    vector<int> vec;
}buffer[550005], *null, *root,*cur=buffer+1,*ans[550005],*que[555005];
struct info
{
    string str;
    int id;
}src[100005];
char str[1000005];
int tag[550005];
node *newnode()
{
    cur++;
    cur->fail=null;
    for(int i = 0; i < 26; i++)
        cur->c[i]=null;
    return cur;
}
void insert(int k)
{
    node *now = root;
    for(int i=0;str[i];i++)
    {
        int tmp = str[i] - 'a';
        if(now->c[tmp] == null)
            now->c[tmp] = newnode();
        now = now->c[tmp];
    }
    ans[k]=now;
}
void build_ac()
{
    int head=1,tail=1;
    tail++;
    que[head]=root;
    root->fail=null;
    while(head<tail)
    {
        node *now =que[head++], *p;
        for(int i=0;i<26;i++)
            if(now->c[i]!=null)
            {
                for(p=now->fail; p!=null && p->c[i]==null;p=p->fail);

                if(p!=null) now->c[i]->fail=p->c[i];
                else now->c[i]->fail=root;
                que[tail++]=now->c[i];
            }
    }
}
bool com(info a,info b)
{
	if(a.str.length() != b.str.length())
		return a.str.length()<b.str.length();
	if(a.str!=b.str) 
		return a.str<b.str;
	return a.id<b.id;
}
int main() 
{
    int n,m;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
    {
        scanf("%s",str);
        src[i].str = str;
        src[i].id = i;
    }
    sort(src+1, src+1+n, com);
    scanf("%d", &m);
    null = &buffer[0];
    null->fail = null;
    for(int i = 0; i < 26; i++)
	    null->c[i] = null;
    root = newnode();
    //puts("fuck ccccccccc");
    for(int i = 1; i <= m; i++)
    {
        scanf("%s",str);
        insert(i);
    }
    build_ac();
    node *now = root;
    for(int  i = 1; i <= n; i++)
    {
        now = root ;
        for(int j = 0; j < src[i].str.length(); j++)
        {
            int tmp = src[i].str[j]-'a';
            while(now != null && now->c[tmp] == null)
                now = now->fail;
            if(now->c[tmp] != null)
                now = now->c[tmp];
            if(now == null)
                now = root;
            for(node *p = now; p!=null && tag[p-buffer] != i; p = p->fail)
            {
                tag[p-buffer]=i;
                if(p->vec.size() < 10)
					p->vec.pb(src[i].id);
            }
        }
    }
    for(int i = 1; i <= m; i++)
    {
        if(ans[i]->vec.size()>0)
        {
            for(int j = 0; j < min((int)ans[i]->vec.size(),10)-1; j++)
                printf("%d ",ans[i]->vec[j]);
            printf("%d",ans[i]->vec[min((int)ans[i]->vec.size(),10)-1]);
        }
        else printf("-1");
        puts("");
    }
    return 0;
}

