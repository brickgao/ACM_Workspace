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

int n, m;
int rec[1010];

int main() {
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++ i) {
        scanf("%d", &rec[i]);
    }
    sort(rec, rec + m);
    int ans = maxint;
    for(int i = 0; i < m - n + 1; ++ i) {
        //cout << i + n - 1 << " " << i << endl;
        ans = min(ans, rec[i + n - 1] - rec[i]);
    }
    printf("%d\n", ans);
    return 0;
}

