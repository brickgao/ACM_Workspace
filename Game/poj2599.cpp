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

int n, k;
vector <int> p[MAXN];
int sg[MAXN];

int getsg(int fr, int u) {
    //cout << u << endl;
    if(sg[u] >= 0)  return  sg[u];
    bool vis[MAXN] = {0};
    for(int i = 0; i < SZ(p[u]); ++ i) {
        int v = p[u][i];
        if(v != fr)
            vis[getsg(u, v)] = true;
    }
    int i = 0;
    while(vis[i])   ++ i;
    return  sg[u] = i;
}

int main() {
    while(scanf("%d%d", &n, &k) != EOF) {
        for(int i = 0; i < MAXN; ++ i)  p[i].clear();
        for(int i = 0; i < n - 1; ++ i) {
            int u, v;
            scanf("%d%d", &u, &v);
            p[u].push_back(v);
            p[v].push_back(u);
        }
        memset(sg, -1, sizeof(sg));
        sg[k] = getsg(-1, k);
        if(sg[k]) {
            int ans = MAXN;
            for(int i = 0; i < SZ(p[k]); ++ i) {
                int v = p[k][i];
                if(sg[v] == 0)
                    ans = min(ans, v);
            }
            printf("First player wins flying to airport %d\n", ans);
        }
        else
            puts("First player loses");
    }
    return 0;
}

