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

int mv[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int n, m;
int mp[110][110];
int vis[110][110];

void dfs_sea(int x, int y, int dep) {
    vis[x][y] = 0;
    for(int i = 0; i < 4; ++ i) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];
        if(nx < 0 || nx > n + 1)    continue;
        if(ny < 0 || ny > m + 1)    continue;
        if(vis[nx][ny] == -1 && mp[nx][ny] - dep <= 0)
            dfs_sea(nx, ny, dep);
    }
}

void dfs_land(int x, int y) {
    vis[x][y] = 1;
    for(int i = 0; i < 4; ++ i) {
        int nx = x + mv[i][0];
        int ny = y + mv[i][1];
        if(nx < 0 || nx > n)    continue;
        if(ny < 0 || ny > m)    continue;
        if(vis[nx][ny] == -1)
            dfs_land(nx, ny);
    }
}

int main() {
    int caseno = 1;
    while(scanf("%d%d", &n, &m) != EOF) {
        if(n == 0 && m == 0)    break;
        int l = 0, r = 0;
        memset(mp, 0, sizeof(mp));
        for(int i = 1; i <= n; ++ i)
            for(int j = 1; j <= m; ++ j) {
                scanf("%d", &mp[i][j]);
                get_max(r, mp[i][j]);
            }
        -- r;
        bool flag = false;
        while(l < r) {
            int ret = 0;
            int mid = (l + r) >> 1;
            memset(vis, -1, sizeof(vis));
            dfs_sea(0, 0, mid);
            for(int i = 1; i <= n; ++ i)
                for(int j = 1; j <= m; ++ j) {
                    if(vis[i][j] == -1) {
                        ++ ret;
                        dfs_land(i, j);
                    }
                }
            //cout << l << " " << r << " " << ret << endl;
            if(ret > 1)     flag = true;
            if(l == mid)    break;
            if(ret > 1)     r = mid;
            else            l = mid;
        }
        printf("Case %d: ", caseno ++);
        if(flag)    printf("Island splits when ocean rises %d feet.\n", r);
        else        puts("Island never splits.");
    }
    return 0;
}

