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

LL n, ans1, ans2;

int main() {
    while(scanf("%lld", &n) != EOF) {
        ans1 = (1 + n) * (n / 2);
        printf("%lld %lld\n", ans1, ans2);
        //TODO
    }
    return 0;
}

