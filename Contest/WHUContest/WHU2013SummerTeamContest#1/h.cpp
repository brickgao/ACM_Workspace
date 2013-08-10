#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
const double eps = 1e-15;
const int MAXN = 10000, MAXM = 200001;
using namespace std;
int n, m;
double M;
struct Tmincut
{
    int s, t;
    int tot, e[MAXN], v[MAXM * 2], next[MAXM * 2];
    double c[MAXM * 2];
    int h[MAXN], vh[MAXN];
    bool S[MAXN];
    Tmincut() { tot = 1; }
    void init()
    {
        s=t=0;
        tot=1;
        memset(e,0,sizeof(e));
        memset(v,0,sizeof(v));
        memset(next,0,sizeof(next));
        memset(c,0,sizeof(c));
        memset(h,0,sizeof(h));
        memset(vh,0,sizeof(vh));
        memset(S,0,sizeof(S));
    }
    void add(int A, int B, double C)
    {
        ++tot; next[tot] = e[A]; e[A] = tot; v[tot] = B; c[tot] = C;
        ++tot; next[tot] = e[B]; e[B] = tot; v[tot] = A; c[tot] = 0;
    }
    void reinit(double t)
    {
        for (int i = 1; i <= tot; i++) 
            if (!(i & 1)) 
                c[i] += c[i ^ 1], c[i ^ 1] = 0;
        for (int i = tot - 2 * n + 1; i <= tot; i++) 
            if (!(i & 1)) 
                c[i] = t;
    }   
    double aug(int x, double f)
    {
        if (x == t) return f;
        int minh = t - 1; double augc = f;
        for (int i = e[x]; i; i = next[i]) if (fabs(c[i]) > eps){
            if (h[v[i]] + 1 == h[x]){
                double t = aug(v[i], min(f, c[i]));
                c[i] -= t; c[i ^ 1] += t; f -= t;
                if (fabs(f) < eps || h[s] == t) return augc - f;
            }
            minh = min(minh, h[x]);
        }
        if (fabs(f - augc) < eps){ if (--vh[h[x]] == 0) h[s] = t; ++vh[h[x] = minh + 1]; }
        return augc - f;
    }
    void dfs(int x)
    {
        S[x] = true;
        for (int i = e[x]; i; i = next[i]) 
            if (fabs(c[i]) > eps && !S[v[i]]) 
                dfs(v[i]);
    }
    double run()
    {
        for (int i = 0; i <= t; i++) 
            h[i] = 0, vh[i] = 0;
        vh[0] = t;
        double flow = 0;
        while(h[s] < t) 
            flow += aug(s, 1e8);
        for (int i = 1; i <= t; i++) 
            S[i] = false;
        return m - flow;
    }
} cut;
vector<int> vec;
int main()
{
    scanf("%d %d", &n, &m);
    while(1)
    {
        cut.init();
        vec.clear();
        if (m == 0) 
        { 
            printf("1\n1\n"); 
            if(scanf("%d %d",&n,&m)!=EOF) 
            {
                puts("");
                continue;
            }
            else break;
        }   
        cut.s = n + m + 1; cut.t = cut.s + 1;
        for (int i = 1; i <= m; i++)
        {
            int a, b; scanf("%d%d", &a, &b);
            cut.add(i, a + m, 1e8); 
            cut.add(i, b + m, 1e8);
        }
        for (int i = 1; i <= m; i++) 
            cut.add(cut.s, i, 1);
        for (int i = 1; i <= n; i++) 
            cut.add(i + m, cut.t, 0);
        double l = 0, r = m;
        while(r - l > 1e-5)
        {
            M = (l + r) / 2; 
            cut.reinit(M);
            if (fabs(cut.run()) < eps) r = M;
            else l = M;
        }
        cut.reinit(l); cut.run(); cut.dfs(cut.s);
        int ans = 0;
        for (int i = m + 1; i <= n + m; i++) 
        {
            if (cut.S[i]) 
            {
                ++ans;
                vec.push_back(i-m);
            }
        }
        printf("%d\n", ans);
        sort(vec.begin(),vec.end());
        for(int i = 0;i<ans;i++)
            printf("%d\n",vec[i]);
        if(scanf("%d %d",&n,&m)!=EOF) 
        {
            puts("");
            continue;
        }
        else break;
    }
    return 0;
}

