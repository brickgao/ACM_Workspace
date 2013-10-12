//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <map>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
const int MAXN = 510;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}
map<string, int> mp_g;
map<string, int> mp_b;
string name[MAXN * 2];
int n;
int maze_g[MAXN][MAXN]; //用来存每个女生喜欢第几个男生的程度 排位从1开始
int maze_b[MAXN][MAXN]; //用来存每个男生第几个喜欢的女生是谁 排位从1开始
int match_g[MAXN], match_b[MAXN];
int p[MAXN];

void solve() {
    memset(match_g, -1, sizeof(match_g));
    memset(match_b, -1, sizeof(match_b));
    for(int i = 1; i <= n; ++ i) p[i] = 1; //p[i]用来标记男生的表白次数
    bool flag = true;
    while(flag) {
        flag = false;
        for(int i = 1; i <= n; ++ i) {
            if(match_b[i] == -1 && p[i] <= n) {
                int a = maze_b[i][p[i] ++];
                if(match_g[a] == -1) {
                    match_g[a] = i;
                    match_b[i] = a;
                }
                else {
                    if(maze_g[a][i] < maze_g[a][match_g[a]]) { //如果本轮男生更优秀则选择本轮男生
                        match_b[i] = a;
                        match_b[match_g[a]] = -1;
                        match_g[a] = i;
                    }
                }
                flag = true;
            }
        }
    }
    for(int i = 1; i <= n; ++ i)
        cout << name[i] << " " << name[n + match_b[i]] << endl;
}

int main() {
    while(scanf("%d", &n) != EOF) {
        mp_g.clear();
        mp_b.clear();
        int cnt = 0;
        for(int i = 1; i <= n; ++ i) {
            string boyname, girlname;
            cin >> boyname;
            mp_b[boyname] = i;
            name[i] = boyname;
            for(int j = 1; j <= n; ++ j) {
                cin >> girlname;
                int ret = -1;
                if(mp_g[girlname] == 0) {
                    mp_g[girlname] = ++ cnt;
                    name[n + cnt] = girlname;
                    ret = cnt;
                }
                else {
                    ret = mp_g[girlname];
                }
                maze_b[i][j] = ret;
            }
        }
        for(int i = 1; i <= n; ++ i) {
            string girlname, boyname;
            cin >> girlname;
            int pos1 = mp_g[girlname];
            for(int j = 1; j <= n; ++ j) {
                cin >> boyname;
                int pos2 = mp_b[boyname];
                maze_g[pos1][pos2] = j;
            }
        }
        solve();
    }
    return 0;
}

