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

typedef struct matrix {
    LL mat[510][510];
    void clear() { memset(mat, 0, sizeof(mat));}
    matrix() {memset(mat, 0, sizeof(mat));}
} matrix;

LL n, m, d, k;
LL rec[510];
matrix ma, ans;

matrix operator * (matrix &a, matrix &b) {
    matrix c;
    for(int i = 0; i <= 0; ++ i) {
        for(int j = 0; j < n; ++ j) {
            for(int k = 0; k < n; ++ k) {
                c.mat[i][j] += a.mat[i][k] * b.mat[k][j] % m;
                c.mat[i][j] %= m;
            }
        }
    }
    for(int i = 1; i < n; ++ i) {
        for(int j = 0; j < n; ++ j)
            c.mat[i][j] = c.mat[0][(j - i + n) % n];
    }
    return c;
}


int main() {
    while(scanf("%lld%lld%lld%lld", &n, &m, &d, &k) != EOF) {
        for(int i = 0; i < n; ++ i)
            scanf("%lld", &rec[i]);
        ans.clear();
        ma.clear();
        ma.mat[0][0] = 1;
        for(int i = 1; i <= d; ++ i) {
            ma.mat[0][(0 - i + n) % n] = 1;
            ma.mat[0][(0 + i + n) % n] = 1;
        }
        for(int i = 1; i < n; ++ i)
            for(int j = 0; j < n; ++ j)
                ma.mat[i][j] = ma.mat[0][(j - i + n) % n];
        for(int i = 0; i < n; ++ i)
            ans.mat[i][i] = 1;
        for(; k > 0; k = k / 2, ma = ma * ma)
            if(k & 1)   ans = ans * ma;
//        for(int i = 0; i < n; ++ i) {
//            for(int j = 0; j < n; ++ j) {
//                if(j)   printf(" ");
//                printf("%d", ans.mat[i][j]);
//            }
//            puts("");
//        }
        for(int i = 0; i < n; ++ i) {
            LL res = 0;
            if(i)   printf(" ");
            for(int j = 0; j < n; ++ j) {
                res = (res + ans.mat[i][j] * rec[j]) % m;
                res %= m;
            }
            printf("%lld", res);
        }
        puts("");
    }
    return 0;
}

