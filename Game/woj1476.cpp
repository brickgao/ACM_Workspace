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

int sg[1010];

int getsg(int u) {
    if(sg[u] >= 0)  return sg[u];
    bool vis[1010] = {0};
    for(int i = 2; i <= u; ++ i) {
        vis[getsg(i - 2) ^ getsg(u - i)] = true;
    }
    int i = 0;
    while(vis[i])   ++ i;
    return sg[u] = i;
}

int main() {
    int t, n;
    memset(sg, -1, sizeof(sg));
    while(scanf("%d", &t) != EOF) {
        int caseno = 1;
        while(t --) {
            scanf("%d", &n);
            int res = 0; 
            for(int i = 0; i < n; ++ i) {
                int rec1 = 0, rec2 = 0;
                for(int j = 0; j < n; ++ j) {
                    int tmp;
                    scanf("%d", &tmp);
                    if(tmp == 1) {
                        if(j & 1) {
                            res ^= getsg(rec1);
                            rec1 = 0;
                        }
                        else {
                            res ^= getsg(rec2);
                            rec2 = 0;
                        }
                    }
                    else {
                        if(j & 1)   ++ rec1;
                        else        ++ rec2;
                    }
                }
                res ^= getsg(rec1);
                res ^= getsg(rec2);
            }
            printf("Case %d: ", caseno ++);
            if(res == 0)    puts("Bob");
            else            puts("Alice");
        }
    }
    return 0;
}

