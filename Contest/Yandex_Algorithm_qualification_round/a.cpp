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

int n, l;
int t, d;
int s[4];

int main() {
    while(scanf("%d%d", &n, &l) != EOF) {
        memset(s, 0, sizeof(s));
        for(int i = 0; i < n; ++ i) {
            scanf("%d%d", &t, &d);
            if(d == -1)
                s[t] ++;
            else if(d > l)  
                s[t] += 3;
            else
                s[t] += 2;
        }
        printf("%d:%d\n", s[1], s[2]);
    }
    return 0;
}

