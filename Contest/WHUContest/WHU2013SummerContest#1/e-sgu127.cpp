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

int k, n;
int rec[8010];
char s[8010][6];

int main() {
    while(scanf("%d%d", &k, &n) != EOF) {
        for(int i = 0; i < n; ++ i) {
            scanf("%d", &rec[i]);
        }
        sort(rec, rec + n);
        for(int i = 0; i < n; ++ i) {
            sprintf(s[i], "%d", rec[i]);
        }
        char bef = s[0][0];
        int tmp = 1, ans = 2;
        for(int i = 1; i < n; ++ i) {
            if(s[i][0] != bef) {
                if(tmp % k != 0)    ans += tmp / k + 1;
                else                ans += tmp / k;
                tmp = 1;
                bef = s[i][0];
            }
            else
                ++ tmp;
        }
        if(tmp % k != 0)    ans += tmp / k + 1;
        else                ans += tmp / k;
        printf("%d\n", ans);
    }
    return 0;
}

