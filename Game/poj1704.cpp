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

int t, n;
int p[1010];

int main() {
    while(scanf("%d", &t) != EOF) {
        for(int i = 0; i < t; ++ i) {
            scanf("%d", &n);
            for(int j = 0; j < n; ++ j)
                scanf("%d", &p[j]);
            p[n] = 0;
            sort(p, p + n + 1);
            int ans = 0;
            for(int j = n; j >= 1; j -= 2) {
                int tmp = p[j] - p[j - 1] - 1;
                //cout << j << " " << j - 1 << endl;
                //cout << tmp << endl;
                ans ^= tmp;
            }
            if(ans == 0)
                puts("Bob will win");
            else
                puts("Georgia will win");
        }
    }
    return 0;
}

