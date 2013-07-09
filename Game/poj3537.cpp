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
const int MAXN = 2010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int n;
int sg[MAXN];

int getsg(int x) {
    //cout << x << endl;
    if(x <= 3)      return sg[x] = 1;
    if(sg[x] >=0)   return sg[x];
    bool vis[MAXN] = {0};
    int i = 0;
    for(int i = 1; i <= x; ++ i) {
        if(i > 3) {
            if(i < x - 2) {
                vis[getsg(i - 3) ^ getsg(x - i - 2)] = true;
            }
            else {
                vis[getsg(i - 3)] = true;
            }
        }
        else {
            if(i < x - 2) {
                vis[getsg(x - i - 2)] = true;
            }
            else {
                vis[0] = true;
            }
        }
    }
    while(vis[i])   ++ i;
    return sg[x] = i;
}

int main() {
    while(scanf("%d", &n) != EOF) {
        memset(sg, -1, sizeof(sg));
        int ans = getsg(n);
        if(ans == 0)
            puts("2");
        else
            puts("1");
    }
    return 0;
}

