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
#define lson l, m, rt << 1
#define rson m + 1, r, rt << 1 | 1
const int maxn = 500010;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

const int antiprime[]={1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,
1260,1680,2520,5040,7560,10080,15120,20160,25200,27720,
45360,50400,55440,83160,110880,166320,221760,277200,
332640,498960,554400,665280};
const int factorNum[]={1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,
90,96,100,108,120,128,144,160,168,180,192,200,216,224};
int index;
int sum[maxn << 2];
char name[maxn][20];
int a[maxn];
int rank[maxn];

void PushUP(int rt) {
    sum[rt] = sum[rt << 1] + sum[rt << 1 | 1];
}

void build(int l, int r, int rt) {
    sum[rt] = r - l + 1;
    if(l == r)  return;
    int m = (l + r) >> 1;
    build(lson);
    build(rson);
}

void update(int p, int l, int r, int rt) {
    if(l == r) {
        sum[rt] --;
        index = l;
        return;
    }
    int m = (l + r) >> 1;
    if(sum[rt << 1] >= p)
        update(p, lson);
    else {
        p -= sum[rt << 1];
        update(p, rson);
    }
    PushUP(rt);
}

int main() {
    int n, k;
    while(scanf("%d%d", &n, &k) != EOF) {
        build(1, n, 1);
        int num = 0;
        while(num < 35 && antiprime[num] <= n) {
            num ++;
        }
        for(int i = 1; i <= n; i ++) {
            scanf("%s %d", name[i], &a[i]);
        }
        index = 0;
        a[0] = 0;
        for(int i = 1; i <= n; i ++) {
            int mod = sum[1];
            if(a[index] > 0)
                k = ((k + a[index] - 2) % mod + mod) % mod + 1;
            else
                k = ((k + a[index] - 1) % mod + mod) % mod + 1;
            update(k, 1, n, 1);
            rank[i] = index;
        }
        printf("%s %d\n", name[rank[antiprime[num - 1]]], factorNum[num - 1]);
    }
    return 0;
}

