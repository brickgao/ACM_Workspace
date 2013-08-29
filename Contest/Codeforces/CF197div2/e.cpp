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

int a[1010];
int ans[4][2];
int n;

bool check() {
    for(int i = 1; i <= n; ++ i)
        if(a[i] != i)   return false;
    return true;
}

bool dfs(int u) {
    if(check()) {
        printf("%d\n", u - 1);
        for(int i = u - 1; i >= 1; -- i) {
            printf("%d %d\n", ans[i][0], ans[i][1]);
        }
        return true;
    }
    if(u > 3)   return false;
    for(int i = 1; i <= n; ++ i)
        if(a[i] != i) {
            ans[u][0] = i;
            for(int j = i + 1; j <= n; ++ j)
                if(a[j] == i) {
                    ans[u][1] = j;
                    reverse(a + i, a + j + 1);
                    if(dfs(u + 1))  return true;
                    reverse(a + i, a + j + 1);
                    break;
                }
            break;
        }
    for(int i = n; i >= 1; -- i)
        if(a[i] != i) {
            ans[u][1] = i;
            for(int j = i - 1; j >= 1; -- j)
                if(a[j] == i) {
                    ans[u][0] = j;
                    reverse(a + j, a + i + 1);
                    if(dfs(u + 1))  return true;
                    reverse(a + j, a + i + 1);
                    break;
                }
            break;
        }
    return false;
}

int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; ++ i)
        scanf("%d", &a[i]);
    dfs(1);
    return 0;
}

