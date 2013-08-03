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

int nx, ny;
int dx[4000], dy[4000], cx[4000], cy[4000];
vector<int> mp[4000];

bool bfs()
{
    bool tag = false;
    queue<int> q;
    memset(dx, 0, sizeof(dx));
    memset(dy, 0, sizeof(dy));
    for(int i = 0; i < nx; i ++)
        if(cx[i] == -1)
            q.push(i);
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(int i = 0; i < (int)mp[u].size(); i ++)
        {
            int v = mp[u][i];
            if(!dy[v])
            {
                dy[v] = dx[u] + 1;
                if(cy[v] == -1)
                    tag = true;
                else
                {
                    dx[cy[v]] = dy[v] + 1;
                    q.push(cy[v]);
                }
            }
        }
    }
    return tag;
}

bool dfs(int u)
{
    for(int i = 0; i < (int)mp[u].size(); i ++)
    {
        int v = mp[u][i];
        if(dy[v] == dx[u] + 1)
        {
            dy[v] = 0;
            if(cy[v] == -1 || dfs(cy[v]))
            {
                cx[u] = v;
                cy[v] = u;
                return true;
            }
        }
    }
    return false;
}

int hk()
{
    int match = 0;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    while(bfs())
    {
        for(int i = 0; i < nx; i ++)
            if(cx[i] == -1 && dfs(i))
                match ++;
    }
    return match;
}

int t;
struct node
{
    int x, y, s;
}a[4000], b[4000];
bool reach(node a, node b)
{
    int s1 = (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
    int s2 = a.s * a.s * t * t;
    if(s2 >= s1) return true;
    return false;
}

int g[110][110];


int main()
{
    while(scanf("%d%d",&nx,&ny) && (nx || ny))
    {
        for(int i = 0; i < 110; i ++)
            for(int j = 0; j < 110; j ++)
                g[i][j] = -1;
        for(int i = 0; i < nx; i ++)
            mp[i].clear();
        for(int i = 0; i < nx; i ++)
        {
            int x, y;
            scanf("%d%d",&x,&y);
            g[x][y] = g[x+1][y] =  i;
        }
        for(int i = 0; i < ny; i ++)
        {
            int x, y;
            scanf("%d%d",&x,&y);
            if(g[x][y] != -1)
                mp[g[x][y]].pb(i);
            if(g[x][y+1] != -1)
                mp[g[x][y+1]].pb(i);
        }
        printf("%d\n",nx + ny - hk());
    }
    return 0;
}

