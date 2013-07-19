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
int map[110][110];

int main() {
    for(int i = 0; i < 110; ++ i)
        for(int j = 0; j < 110; ++ j)
           map[i][j] = 99; 
    for(int i = 0; i < 110; ++ i)
        map[i][i] = 1;
    for(int i = 0; i < 110; ++ i)
        map[i][0] = 1;
    map[0][0] = 2;
    while(scanf("%d", &n) != EOF) {
        for(int i = 0; i < n; ++ i) {
            for(int j = 0; j < n; ++ j) {
                if(j)   printf(" ");
                printf("%d", map[j][i]);
            }
            printf("\n");
        }
        printf("\n");
    }
    return 0;
}

