//By Brickgao
#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <deque>
#include <stack>
using namespace std;
#define out(v) cerr << #v << ": " << (v) << endl
#define SZ(v) ((int)(v).size())
const int maxint = -1u>>1;
template <class T> bool get_max(T& a, const T &b) {return b > a? a = b, 1: 0;}
template <class T> bool get_min(T& a, const T &b) {return b < a? a = b, 1: 0;}

typedef struct record {
    int pos;
    char ch;
} record;

string s;
int vis[100010];

int main() {
    while(cin >> s) {
        stack <record> st;
        record tmp;
        int cnt = 0;
        memset(vis, 0, sizeof(vis));
        tmp.pos = 0, tmp.ch = s[0];
        st.push(tmp);
        for(int i = 1; i < SZ(s); ++ i) {
            if(!st.empty() && s[i] == ')' && st.top().ch == '(') {
                vis[i] = ++ cnt;
                vis[st.top().pos] = cnt;
                st.pop();
                continue;
            }
            if(!st.empty() && s[i] == ']' && st.top().ch == '[') {
                vis[i] = ++ cnt;
                vis[st.top().pos] = cnt;
                st.pop();
                continue;
            }
            tmp.ch = s[i];
            tmp.pos = i;
            st.push(tmp);
        }
        int maxlen = -1, l = -1, r = -1;
        for(int lower = 0; lower < SZ(s); ++ lower) {
            if(vis[lower] == 0) continue;
            int upper = lower + 1;
            while(upper < SZ(s) && vis[upper] != 0) {
                ++ upper;
            }
            if(upper - lower > maxlen) {
                maxlen = upper - lower;
                l = lower, r = upper;
            }
            lower = upper - 1;
        }
        if(maxlen == -1)
            puts("");
        else {
            for(int i = l; i < r; ++ i) {
                printf("%c", s[i]);
            }
            puts("");
        }
        puts("");
    }
    return 0;
}

