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

int n, m;
vector <int> a;
LL ans;

int main() {
    a.clear();
    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; ++ i) {
        int tmp;
        scanf("%d", &tmp);
        if(SZ(a) != 0 && tmp == a[SZ(a) - 1])   continue;
        a.push_back(tmp);
    }
    ans = 0;
    if(SZ(a) == 1) {
        printf("%d\n", a[0] - 1);
        return 0;
    }
    for(int i = 1; i < SZ(a); ++ i) {
        if(a[i] < a[i - 1])
            ans += (LL)n;
    }
    ans += (LL)a[SZ(a) - 1] - 1LL;
    cout << ans << endl;
    return 0;
}

