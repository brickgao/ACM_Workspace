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

typedef struct record {
    int num, r;
    bool operator < (const record &cmp) const {
        return r < cmp.r;
    }
} record;

int t;
int n, m, y;
int X[1010], XM[1010], K[1010];
record rec[1010];

int main() {
    while(scanf("%d", &t) != EOF) {
        for(int T = 0; T < t; ++ T) {
            bool blank = false;
            if(blank)   puts("");
            else    blank = true;
            scanf("%d%d%d", &n, &m, &y);
            int left = m;
            for(int i = 0; i < n; ++ i) {
                scanf("%d", &X[i]);
                XM[i] = m * X[i];
            }
            for(int i = 0; i < n; ++ i) {
                K[i] = XM[i] / y;
                left -= K[i];
            }
            for(int i = 0; i < n; ++ i) {
                rec[i].r = abs(K[i] * y - XM[i]) - abs((K[i] + 1) * y - XM[i]);
                rec[i].num = i;
            }
            sort(rec, rec + n);
            for(int i = n - 1; i >= 0; -- i) {
                if(left <= 0)   break;
                K[rec[i].num] ++;
                left --;
            }
            for(int i = 0; i < n; ++ i) {
                if(i)   printf(" ");
                printf("%d", K[i]);
            }
            puts("");
        }
    }
    return 0;
}

