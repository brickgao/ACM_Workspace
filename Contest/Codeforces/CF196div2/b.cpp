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
const double eps = 1e-8;
inline int sgn(const double x) {return (x > eps) - (x < -eps);}
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int ans1, ans2;
double num = maxint;

int gcd(int a, int b) {
    return b?gcd(b, a % b): a;
}


int main() {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if(a * d == b * c) {
        puts("0/1");
        return 0;
    }
    //cout << a << " " << b << " " << c << " " << d << endl;
    int tmp1, tmp2;
    double tmpnum;
    if(a / c * d <= b) {
        tmp1 = b * c - a * d;
        tmp2 = b * c;
        tmpnum = (double)tmp1 / (double)tmp2;
        if(sgn(tmpnum) > 0 && sgn(tmpnum - num) < 0) {
            ans1 = tmp1, ans2 = tmp2;
            num = tmpnum;
        }
    }
    if(b / d * c <= a) {
        tmp1 = a * d - b * c;
        tmp2 = a * d;
        tmpnum = (double)tmp1 / (double)tmp2;
        if(sgn(tmpnum) > 0 && sgn(tmpnum - num) < 0) {
            ans1 = tmp1, ans2 = tmp2;
            num = tmpnum;
        }
    }
    int div = gcd(ans1, ans2);
    ans1 /= div;
    ans2 /= div;
    printf("%d/%d\n", ans1, ans2);
    return 0;
}

