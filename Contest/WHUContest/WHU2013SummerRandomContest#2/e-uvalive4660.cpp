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

int t;
int a, b;

int main() {
    while(scanf("%d", &t) != EOF) {
        char s[100];
        while(t --) {
            scanf("%d%d", &a, &b);
            sprintf(s, "%d", a);
            int len = strlen(s);
            char maxn = 0;
            int num = 0;
            int ans = 0;
            for(int i = 0; i < len; ++ i)
                maxn = max(s[i], maxn);
            num = maxn - '0' + 1;
            for(int i = 0; i < len; ++ i) {
                ans += (s[i] - '0') * (int)pow(num, len - i - 1);
            }
            sprintf(s, "%d", b);
            len = strlen(s);
            maxn = 0;
            for(int i = 0; i < len; ++ i)
                maxn = max(s[i], maxn);
            num = maxn - '0' + 1;
            for(int i = 0; i < len; ++ i)
                ans += (s[i] - '0') * (int)pow(num, len - i - 1);
            printf("%d\n", ans);
        }
    }
    return 0;
}

