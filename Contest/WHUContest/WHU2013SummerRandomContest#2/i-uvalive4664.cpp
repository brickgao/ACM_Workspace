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

int rec[4000010];
int sum1[2000010], sum2[2000010];
int n, m, a, b;

int main() {
    while(scanf("%d", &n) != EOF) {
        scanf("%d%d%d%d", &rec[0], &a, &b, &m);
        sum1[0] = rec[0];
        for(int i = 1; i <= 2 * n + 1; ++ i) {
            rec[i] = (a * rec[i - 1] + b) % m;
            if(i == 1)  {sum2[0] = rec[1]; continue;}
            if(i % 2 == 0)  sum1[i / 2] = sum1[i / 2 - 1] + rec[i];
            else            sum2[i / 2] = sum2[i / 2 - 1] + rec[i];
        }
        double ans = 0.0;
        if(rec[0] == 0 && b == 0)   ans = 1.0;
        for(int L = 0; L <= n; ++ L) {
            if(n > 20 && L == 10)   L = n - 10;
            for(int H = L; H <= n; ++ H) {
                if(n > 20 && H == 10)   H = n - 10;
                int tp, fn, fp;
                if(L != 0)  tp = sum1[H] - sum1[L - 1];
                else        tp = sum1[H];
                fn = sum1[n] - tp;
                if(L != 0)  fp = sum2[H] - sum2[L - 1];
                else        fp = sum2[H];
                //cout << L << " " << H << endl;
                //cout << tp << " " << fn << " " << fp << endl;
                double p = (double)tp / ((double)tp + (double)fp);
                double r = (double)tp / ((double)tp + (double)fn);
                double f = (2.0 * p * r) / (p + r);
                if(f > ans)     ans = f;
            }
        }
        if(sum1[n] == 0)    ans = 1.0;
        printf("%.6lf\n", ans);
    }
    return 0;
}

