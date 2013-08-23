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
#define LL long long
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int n;
int fa[12], ans = maxint;
LL a[12], used[12], cnt[12];

void gao() {
    int ret = 0;
    int t = 0;
    for(int i = 0; i < n; ++ i) {
        if(fa[i] == -1) {
            ret += cnt[i];
            ++ t;
        }
        if(cnt[i] == 1) -- ret;
    }
    ret += n;
    if(t > 1)    ++ ret;
    ans = min(ans, ret);
}

void dfs(int u) {
    if(u >= n) {
        gao();
        return;
    }
    for(int i = u + 1; i < n; ++ i)
        if((a[i] / used[i]) % a[u] == 0) {
            used[i] *= a[u];
            fa[u] = i;
            dfs(u + 1);
            used[i] /= a[u];
        }
    fa[u] = -1;
    dfs(u + 1);
}

int main() {
    scanf("%d", &n);
    for(int i = 0; i < n; ++ i)
        cin >> a[i];
    memset(fa, -1, sizeof(fa));
    sort(a, a + n);
    for(int i = 0; i < n; ++ i) {
        used[i] = 1;
        LL tmp = a[i];
        for(int j = 2; j <= sqrt(a[i]) + 1; ++ j)
            while(tmp % j == 0) {
                tmp /= j;
                ++ cnt[i];
            }
        if(tmp > 1)
            ++ cnt[i];
    }
    dfs(0);
    cout << ans << endl;
    return 0;
}

