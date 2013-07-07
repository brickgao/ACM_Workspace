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

int n;
int rec[1010];
int ans;

int main() {
    while(scanf("%d", &n) != EOF && n != 0) {
        for(int i = 0; i < n; ++ i) {
            scanf("%d", &rec[i]);
        }
        ans = rec[0];
        for(int i = 1; i < n; ++ i) {
            ans ^= rec[i];
        }
        if(ans == 0) {
            puts("0");
            continue;
        }
        int ansn = 0;
        for(int i = 0; i < n; ++ i) {
            int tmp = ans ^ rec[i];
            if(tmp < rec[i])    ansn ++;
        }
        printf("%d\n", ansn);
    }
    return 0;
}

