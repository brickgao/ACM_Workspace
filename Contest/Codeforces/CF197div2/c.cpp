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

int m;
string s;
vector <int> ans;
bool flag = false;
int rec[1010];
int num[2] = {};

void dfs(int u, int t, int dep) {
    rec[dep] = u;
    if(dep >= m) {
        flag = true;
        puts("YES");
        for(int i = 1; i <= m; ++ i) {
            if(i > 1)   printf(" ");
            printf("%d", rec[i]);
        }
        puts("");
        return;
    }
    for(int i = 0; i < SZ(ans); ++ i) {
        if(ans[i] == u) continue;
        if(num[t ^ 1] + ans[i] > num[t]) {
            num[t ^ 1] += ans[i];
            dfs(ans[i], t ^ 1, dep + 1);
            num[t ^ 1] -= ans[i];
            if(flag)    return;
        }
    }
}

int main() {
    cin >> s;
    scanf("%d", &m);
    for(int i = 0; i < SZ(s); ++ i) {
        if(s[i] == '1') {
            ans.push_back(i + 1);
        }
    }
    sort(ans.begin(), ans.end());
    for(int i = 0; i < SZ(ans); ++ i) {
        num[0] = num[1] = 0;
        num[0] = ans[i];
        dfs(ans[i], 0, 1);
        if(flag)    return 0;
    }
    puts("NO");
    return 0;
}

