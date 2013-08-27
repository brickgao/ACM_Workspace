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

string s;
vector <int> ans;

int main() {
    cin >> s;
    ans.clear();
    int pos = 0;
    int num = 0;
    while(pos < SZ(s)) {
        if(s[pos] == '+') {
            ans.push_back(num);
            num = 0;
        }
        else {
            num *= 10;
            num += s[pos] - '0';
        }
        ++ pos;
    }
    ans.push_back(num);
    sort(ans.begin(), ans.end());
    for(int i = 0; i < SZ(ans); ++ i) {
        if(i)   printf("+");
        printf("%d", ans[i]);
    }
    puts("");
    return 0;
}

