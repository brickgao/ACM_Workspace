//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

int a[5010];
int sum, minn, n;

int main() {
    while(scanf("%d", &n) != EOF) {
        sum = 0;
        for(int i = 0; i < n; i ++) {
            scanf("%d", &a[i]);
            for(int j = 0; j < i; j ++) {
                if(a[j] > a[i]) sum ++;
            }
        }
        minn = sum;
        for(int i = 0; i < n; i ++) {
            sum = sum - a[i] + (n - a[i] - 1);
            minn = min(minn, sum);
        }
        printf("%d\n", minn);
    }
    return 0;
}

