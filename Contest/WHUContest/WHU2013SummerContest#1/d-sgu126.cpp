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

int a, b;

inline int gcd(int x, int y){
    if (!x || !y) return x > y ? x : y;
    for (int t; t = x % y; x = y, y = t);
    return y;
}

inline void my_swap() {
    int tmp;
    if(a > b) {
        tmp = a;
        a = b;
        b = tmp;
    }
}

int main() {
    while(scanf("%d%d", &a, &b) != EOF) {
        my_swap();
        if(a == 0)  { puts("0");   continue;}
        int div = gcd(a, b);
        a /= div, b /= div;
        int sum = a + b;
        int ti = 0;
        while(sum != 0) {
            if(sum & 1) ++ ti;
            sum = sum >> 1;
        }
        if(ti != 1) {
            puts("-1");
        }
        else {
            int ans = 1;
            while(a != b) {
                my_swap();
                b -= a;
                a *= 2;
                ++ ans;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}

