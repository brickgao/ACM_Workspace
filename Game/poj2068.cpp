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

int n, s;
int p[25];
int sg[25][10000];

int getsg(int x, int y) {
    //cout << x << " " << y << endl;
    if(x >= n * 2)  return getsg(x - n * 2, y);
    if(y == 0)  return sg[x][y] = 0;
    if(sg[x][y] >= 0)   return sg[x][y];
    bool vis[10000] = {0};
    for(int i = max(y - p[x], 0); i < y; ++ i) {
        vis[getsg(x + 1, i)] = true;
    }
    int i = 0;
    while(vis[i])   ++ i;
    return sg[x][y] = i;
}

int main() {
    while(scanf("%d", &n) != EOF && n != 0) {
        memset(sg, -1, sizeof(sg));
        scanf("%d", &s);
        for(int i = 0; i < n; ++ i) {
            scanf("%d%d", &p[i * 2], &p[i * 2 + 1]);
        }
        int ans = getsg(0, s - 1);
        if(ans == 0)
            puts("0");
        else
            puts("1");
    }
    return 0;
}

