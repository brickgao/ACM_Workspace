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

int k, l;

int main() {
    while(scanf("%d", &k) != EOF) {
        bool flag = false;
        int len = (int)sqrt(k) + 1;
        for(l = 2; l <= len; l ++) {
            if(k % (l + 1) == 0) {
                printf("%d\n", l);
                flag = true;
                break;
            }
        }
        if(flag)    continue;
        if(k % 2 == 0 && k / 2 - 1 >= 2) {
            printf("%d\n", k / 2 - 1);
            continue;
        }
        if(k - 1 >= 2) {
            printf("%d\n", k - 1);
            continue;
        }
        puts("0");
    }
    return 0;
}

