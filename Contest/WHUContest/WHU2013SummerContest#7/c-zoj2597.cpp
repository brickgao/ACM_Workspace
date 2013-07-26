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

vector <string> s[15];
int n, N;

int main() {
    bool blank = false;
    s[1].push_back("0");    s[1].push_back("1");
    s[2].push_back("00");   s[2].push_back("10");
    s[2].push_back("01");   s[2].push_back("11");
    for(int i = 3; i <= 12; ++ i) {
        int len1, len2;
        if(i % 2 == 0) {
            len1 = len2 = i / 2;
        }
        else {
            len1 = i / 2;
            len1 *= 2;
            len2 = i - len1;
        }
        for(int j = 0; j < (1 << len2); ++ j) {
            for(int k = 0; k < (1 << len1); ++ k) {
                s[i].push_back(s[len1][k] + s[len2][(k + j) % SZ(s[len2])]);
            }
        }
    }
    while(scanf("%d", &n) != EOF && n != 0) {
        if(blank)   puts("");
        else        blank = true;
        for(int i = 0; i < SZ(s[n]); ++ i) {
            cout << s[n][i] << endl;
        }
    }
    return 0;
}

