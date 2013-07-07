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
const int Maxn = 210;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int m, n;
int sg[Maxn][Maxn];

int getsg(int x, int y) {
    if(sg[x][y] >= 0)    return sg[x][y];
    bool vi[Maxn];
    memset(vi, false, sizeof(vi));
    for(int i = 2; i <= x - i; i ++) {
        vi[getsg(i, y) ^ getsg(x - i, y)] = true;
    }
    for(int i = 2; i <= y - i; i ++) {
        vi[getsg(x, i) ^ getsg(x, y - i)] = true;
    }
    int i = 0;
    while(vi[i])    i ++;
    return  sg[x][y] = sg[y][x] = i;
}

int main() {
//    bool vi[Maxn];
//    memset(vi, false, sizeof(vi));
//    for(int i = 0; i < Maxn; i ++)
//        if(vi[i])    cout << 1 << " ";
//        else            cout << 0 << " ";
//    cout << endl;
    memset(sg, -1, sizeof(sg));
    for(int i = 2; i <= 200; i ++)
        for(int j = 2; j <= i; j ++)
            getsg(i, j);
    while(scanf("%d%d", &m, &n) != EOF) {
        if(sg[m][n] != 0)
            puts("WIN");
        else
            puts("LOSE");
    }
    return 0;
}

