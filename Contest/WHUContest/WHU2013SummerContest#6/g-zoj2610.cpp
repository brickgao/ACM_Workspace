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

int caseno = 1;
int n;
string s[60];

int main() {
    while(scanf("%d", &n) != EOF && n != 0) {
        for(int i = 0; i < n; ++ i) {
            cin >> s[i];
        }
        bool ans1 = true;
        for(int i = 0; i < n; ++ i) {
            int res = 0;
            for(int j = 1; j < SZ(s[i]); ++ j) {
                if(s[i][j] != s[i][j - 1])
                    ++ res;
            }
            if(res > 1)
                ans1 = false;
        }
        bool ans2 = true;
        for(int i = 0; i < 2 * n - 1; i += 2) {
            int res = 0;
            int bef = s[i / 2][i];
            for(int j = i / 2; j < n; ++ j) {
                if(i + 1 < SZ(s[j]) && s[j][i + 1] != bef) {
                    bef = s[j][i + 1];  ++ res;
                }
                if(s[j][i] != bef) {
                    bef = s[j][i];      ++ res;
                }
            }
            if(res > 1)
                ans2 = false;
        }
        bool ans3 = true;
        for(int i = 0; i < n; ++ i)     reverse(s[i].begin(), s[i].end());
        for(int i = 0; i < 2 * n - 1; i += 2) {
            int res = 0;
            int bef = s[i / 2][i];
            for(int j = i / 2; j < n; ++ j) {
                if(i + 1 < SZ(s[j]) && s[j][i + 1] != bef) {
                    bef = s[j][i + 1];  ++ res;
                }
                if(s[j][i] != bef) {
                    bef = s[j][i];      ++ res;
                }
            }
            if(res > 1)
                ans3 = false;
        }
        printf("Puzzle %d\n", caseno ++);
        if(ans1 || ans2 || ans3)    puts("Parts can be separated");
        else                        puts("Parts cannot be separated");
    }
    return 0;
}

