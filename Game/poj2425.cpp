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
const int MAXN = 1010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int m, n;
int sg[MAXN];
vector <int> p[MAXN];

int getsg(int u) {
    if(sg[u] >= 0)   return sg[u];
    bool vis[MAXN] = {0};
    for(int i = 0; i < SZ(p[u]); ++ i) {
        sg[p[u][i]] = getsg(p[u][i]);
        vis[sg[p[u][i]]] = true;
    }
    int i = 0;
    while(vis[i])   ++ i;
    return sg[u] = i;
}

int main() {
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < MAXN; ++ i)  p[i].clear();
        for(int i = 0; i < n; ++ i) {
            int tmp;
            scanf("%d", &tmp);
            for(int j = 0; j < tmp; ++ j) {
                int tmpv;
                scanf("%d", &tmpv);
                p[i].push_back(tmpv);
            }
        }
        memset(sg, -1, sizeof(sg));
        while(scanf("%d", &m) != EOF && m != 0) {
            int tmp, ans;
            ans = 0;
            for(int i = 0; i < m; ++ i) {
                scanf("%d", &tmp);
                ans ^= getsg(tmp);
            }
            if(ans != 0)
                puts("WIN");
            else
                puts("LOSE");
        }
    }
    return 0;
}

