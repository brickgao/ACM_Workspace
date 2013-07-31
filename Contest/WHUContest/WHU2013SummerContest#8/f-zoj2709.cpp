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

typedef struct record {
    int pos, num, num2;
    bool operator < (const record &cmp) const {
        return num < cmp.num;
    }
} record;

LL c[70][70];
int n;
string s;
record rec[30];

inline LL gcd(LL x, LL y) { 
    if(!x || !y)    return x > y ? x : y;
    for(LL t; t = x % y; x = y, y = t);
    return y;
}

void init() {
    for(int i = 0; i <= 60; i ++) {
        c[i][0] = c[i][i] = 1;
        for(int j = 1; j < i; j ++) {
            c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
        }
    }
}

int main() {
    init();
    while(scanf("%d", &n) != EOF) {
        LL ans1, ans2, ans3, ans4;
        cin >> s;
        ans2 = c[n][SZ(s)];
        for(int i = 0; i < 26; ++ i)
            rec[i].num = 0, rec[i].pos = i, rec[i].num2 = 0;
        for(int i = 0; i < SZ(s); ++ i) {
            int pos = s[i] - 'A';
            ++ rec[pos].num;
        }
        sort(rec, rec + 26);
        int t = -1;
        for(int i = 0; i < 26; ++ i) {
            if(rec[i].num != 0) {
                t = i;
                break;
            }
        }
        int sum = n - SZ(s);
        while(sum > 0) {
            double maxn = 0.0;
            int recpos = -1;
            for(int i = t; i < 26; ++ i) {
                double tmp = (double)(rec[i].num2 + rec[i].num + 1) / (double)(rec[i].num2 + 1);
                if(tmp > maxn) {
                    maxn = tmp;
                    recpos = i;
                }
            }
            ++ rec[recpos].num2;
            -- sum;
        }
        ans1 = 1;
        for(int i = t; i < 26; ++ i)
            ans1 *= c[rec[i].num + rec[i].num2][rec[i].num];
        ans4 = c[n][SZ(s)];
        ans3 = c[n - SZ(s) + rec[t].num][rec[t].num];
        LL div = gcd(ans1, ans2);
        ans1 /= div, ans2 /= div;
        div = gcd(ans3, ans4);
        ans3 /= div, ans4 /= div;
        cout << ans1 << "/" << ans2 << endl;
        cout << ans3 << "/" << ans4 << endl;
        puts("");
    }
    return 0;
}

