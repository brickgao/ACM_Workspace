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
int rec[15];
bool flag[15];

int main() {
    while(scanf("%d", &n) != EOF && n != 0) {
        memset(flag, false, sizeof(flag));
        for(int i = 0; i < n; ++ i) {
            scanf("%d", &rec[i]);
        }
        sort(rec, rec + n);
        for(int i = 1; i < n; ++ i) {
            //cout << i - 1 << " " << i << endl;
            if(rec[i - 1] == rec[i]) {
                flag[i - 1] = flag[i] = true;
                ++ i;
            }
        }
        bool ans = true;
        for(int i = 0; i < n; ++ i) {
            if(!flag[i]) {
                ans = false;
                break;
            }
        }
        if(ans)
            puts("0");
        else
            puts("1");
    }
    return 0;
}

